#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
    const int ratedCapacity = 120;  // Rated capacity of a new battery

  for (int i = 0; i < nBatteries; i++) {
    // Calculate SoH for each battery
    double soh = (double)presentCapacities[i] / ratedCapacity * 100;

    // Classify the battery based on SoH
    if (soh > 80) {
      counts.healthy++;
    } else if (soh >= 65) {
      counts.exchange++;
    } else {
      counts.failed++;
    }
  }

  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 55};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  printf("Done counting :)\n");
  printf("healthy is: %d\n",counts.healthy);
  printf("exchange is: %d\n",counts.exchange);
  printf("failed is: %d\n",counts.failed);
}

int main() {
  testBucketingByHealth();
  return 0;
}
