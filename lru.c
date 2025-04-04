#include <stdio.h>

int main() {
    int n, frames, i, j, pos, faults = 0;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    int frame[frames], time[frames];
    for (i = 0; i < frames; ++i) {
        frame[i] = -1; // Initialize all frames as empty
    }
    
    for (i = 0; i < n; ++i) {
        int flag1 = 0, flag2 = 0;
        
        // Check if the page is already in memory
        for (j = 0; j < frames; ++j) {
            if (frame[j] == pages[i]) {
                flag1 = flag2 = 1;
                time[j] = i; // Update the last usage time
                break;
            }
        }
        
        // Check for an empty frame
        if (flag1 == 0) {
            for (j = 0; j < frames; ++j) {
                if (frame[j] == -1) {
                    faults++;
                    frame[j] = pages[i];
                    time[j] = i; // Store the current time
                    flag2 = 1;
                    break;
                }
            }
        }
        
        // Replace the least recently used page if no empty frame is available
        if (flag2 == 0) {
            int minimum = time[0];
            pos = 0;
            for (j = 1; j < frames; ++j) {
                if (time[j] < minimum) {
                    minimum = time[j];
                    pos = j;
                }
            }
            frame[pos] = pages[i];
            time[pos] = i; // Update the last usage time
            faults++;
        }
        
        // Display the current state of frames
        printf("\nFrames: ");
        for (j = 0; j < frames; ++j) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }
    
    printf("\n\nTotal Page Faults = %d\n", faults);
    
    return 0;
}