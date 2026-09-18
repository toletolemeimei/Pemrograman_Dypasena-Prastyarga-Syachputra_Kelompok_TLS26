#include <iostream>

int main() {
    int N, K;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> K;

    int active[1000];
    for (int i = 1; i <= N; i++) {
        active[i] = 1;
    }

    int remaining = N;
    int currPos = 1;

    std::cout << "\nUrutan eliminasi: ";

    while (remaining > 1) {
        int count = 0;

        while (count < K) {
            if (active[currPos] == 1) {
                count++;
            }
            if (count < K) {
                currPos = (currPos % N) + 1;
            }
        }

        active[currPos] = 0;
        int eliminatedNum = currPos;
        std::cout << eliminatedNum << " ";
        remaining--;

        if (eliminatedNum % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        if (remaining > 1) {
            do {
                currPos = (currPos % N) + 1;
            } while (active[currPos] == 0);
        }
    }

    std::cout << "\nAstronot terakhir yang bertahan: ";
    for (int i = 1; i <= N; i++) {
        if (active[i] == 1) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}