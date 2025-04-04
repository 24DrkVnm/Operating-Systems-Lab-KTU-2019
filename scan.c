#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, totalMovement = 0, direction;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the disk request queue: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    int diskSize;
    printf("Enter the total size of the disk: ");
    scanf("%d", &diskSize);

    // Add the head and boundaries (0 and diskSize - 1) to the request queue
    int extendedRequests[n + 2];
    for (i = 0; i < n; ++i) {
        extendedRequests[i] = requests[i];
    }
    extendedRequests[n] = 0; // Add the lower boundary
    extendedRequests[n + 1] = diskSize - 1; // Add the upper boundary
    n += 2;

    // Sort the request queue
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (extendedRequests[i] > extendedRequests[j]) {
                int temp = extendedRequests[i];
                extendedRequests[i] = extendedRequests[j];
                extendedRequests[j] = temp;
            }
        }
    }

    // Find the position of the head in the sorted queue
    int headIndex = 0;
    for (i = 0; i < n; ++i) {
        if (extendedRequests[i] >= head) {
            headIndex = i;
            break;
        }
    }

    printf("\nDisk head movement:\n");

    // Process requests in the chosen direction
    if (direction == 1) { // Moving right
        for (i = headIndex; i < n; ++i) {
            printf("From %d to %d -> Movement = %d\n", head, extendedRequests[i], abs(extendedRequests[i] - head));
            totalMovement += abs(extendedRequests[i] - head);
            head = extendedRequests[i];
        }
        for (i = headIndex - 1; i >= 0; --i) {
            printf("From %d to %d -> Movement = %d\n", head, extendedRequests[i], abs(extendedRequests[i] - head));
            totalMovement += abs(extendedRequests[i] - head);
            head = extendedRequests[i];
        }
    } else { // Moving left
        for (i = headIndex - 1; i >= 0; --i) {
            printf("From %d to %d -> Movement = %d\n", head, extendedRequests[i], abs(extendedRequests[i] - head));
            totalMovement += abs(extendedRequests[i] - head);
            head = extendedRequests[i];
        }
        for (i = headIndex; i < n; ++i) {
            printf("From %d to %d -> Movement = %d\n", head, extendedRequests[i], abs(extendedRequests[i] - head));
            totalMovement += abs(extendedRequests[i] - head);
            head = extendedRequests[i];
        }
    }

    printf("\nTotal head movement = %d\n", totalMovement);

    return 0;
}