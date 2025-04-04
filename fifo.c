#include<stdio.h>

void main() {
    int n, frames, pages[50], temp[10], faults = 0;
    int i, j, k = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        temp[i] = -1; // Initialize frames to -1 (empty)
    }

    printf("\nPage Reference String\tFrames\n");
    for (i = 0; i < n; i++) {
        int flag = 0;

        // Check if the page is already in a frame
        for (j = 0; j < frames; j++) {
            if (temp[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If the page is not in a frame, replace the oldest page
        if (flag == 0) {
            temp[k] = pages[i];
            k = (k + 1) % frames; // FIFO logic
            faults++;
        }

        // Print the current state of frames
        printf("%d\t\t\t", pages[i]);
        for (j = 0; j < frames; j++) {
            if (temp[j] != -1) {
                printf("%d ", temp[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
}