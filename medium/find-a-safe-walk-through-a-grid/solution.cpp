                int ncost = cost + grid[nx][ny];
                if (ncost < dist[nx][ny]) {
                    dist[nx][ny] = ncost;
                    pq.push({ncost, nx, ny});
                }
            }
        }

        return false;
    }
};
