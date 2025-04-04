#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, totalMovement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the disk request queue: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("\nDisk head movement:\n");
    for (i = 0; i < n; ++i) {
        printf("From %d to %d -> Movement = %d\n", head, requests[i], abs(requests[i] - head));
        totalMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf("\nTotal head movement = %d\n", totalMovement);

    return 0;
}