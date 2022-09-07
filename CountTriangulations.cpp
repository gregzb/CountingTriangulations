#include <vector>
#include <iostream>
#include "CountTriangulations.hpp"
#include "Vec.hpp"
#include "Utils.hpp"

std::vector<std::vector<bool>> calculateDiagonals(const Polygon& polygon) {
    int n = polygon.size();
    std::vector<std::vector<bool>> out(n, std::vector<bool>(n, false));

    auto neighbor_index = [n](int idx, int dir) {
        return (idx + n + dir) % n;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i+2; j < n; j++) {

            if (neighbor_index(j, 1) == i) continue;

            const Point &p1 = polygon.getPoints()[i];
            const Point &p2 = polygon.getPoints()[j];

            bool ok = true;
            for (int k = 0; k < n; k++) {
                int nk = (k+1)%n;

                if (k == i || nk == i || k == j || nk == j) continue;

                const Point &p3 = polygon.getPoints()[k];
                const Point &p4 = polygon.getPoints()[nk];

                if (intersects(p1, p2, p3, p4)) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            Vec midpt = (p1 + p2) / 2;

            if (polygon.containsPoint(midpt)) {
                out[i][j] = true;
            } else {
                // its external
            }

        }
    }
    
    return out;
}

bool isDiagonal(const std::vector<std::vector<bool>> diagonals, size_t i, size_t j) {
    if (i > j) std::swap(i, j);
    return diagonals[i][j];
}

int64_t countTriangulations(const Polygon& polygon) {
    int n = polygon.size();

    if (n < 3) return 0;

    std::vector<std::vector<bool>> diagonals = calculateDiagonals(polygon);
    // printGrid(diagonals);

    std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(n));

    auto neighbor_index = [n](int idx, int dir) {
        return (idx + n + dir) % n;
    };

    for (int i = 0; i < n; i++) {
        int ni = neighbor_index(i, 2);
        if (isDiagonal(diagonals, i, ni) || neighbor_index(ni, 1) == i) dp[i][ni] = 1;
    }
    // printGrid(dp);

    for (int k = 3; k < n; k++) {
        for (int i = 0; i < n; i++) {
            int ni = neighbor_index(i, k);

            if (!isDiagonal(diagonals, i, ni) && !(neighbor_index(ni, 1) == i)) continue;

            dp[i][ni] = dp[i][neighbor_index(ni, -1)] + dp[neighbor_index(i, 1)][ni];
            for (int j = neighbor_index(i, 2); j != neighbor_index(i, k-2+1); j = neighbor_index(j, 1)) {
                dp[i][ni] += dp[i][j] * dp[j][neighbor_index(i, k)];
            }
        }
    }
    // printGrid(dp);

    return dp[0][n-1];
}