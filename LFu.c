#include <stdio.h>

int main() {
    int n, frames, i, j, k, faults = 0, minFreq, pos;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    int frame[frames], freq[frames], time[frames];
    
    // Initialize frames, frequency, and time arrays
    for (i = 0; i < frames; ++i) {
        frame[i] = -1; // Empty frame
        freq[i] = 0;   // Frequency of usage
        time[i] = 0;   // Time of last use
    }
    
    for (i = 0; i < n; ++i) {
        int flag1 = 0, flag2 = 0;
        
        // Check if the page is already in memory
        for (j = 0; j < frames; ++j) {
            if (frame[j] == pages[i]) {
                flag1 = flag2 = 1;
                freq[j]++;       // Increment frequency
                time[j] = i;     // Update the last usage time
                break;
            }
        }
        
        // If the page is not in memory, check for an empty frame
        if (flag1 == 0) {
            for (j = 0; j < frames; ++j) {
                if (frame[j] == -1) {
                    faults++;
                    frame[j] = pages[i];
                    freq[j] = 1;  // Initialize frequency
                    time[j] = i;  // Store the current time
                    flag2 = 1;
                    break;
                }
            }
        }
        
        // If no empty frame is available, replace the least frequently used page
        if (flag2 == 0) {
            minFreq = freq[0];
            pos = 0;
            
            // Find the page with the least frequency
            for (j = 1; j < frames; ++j) {
                if (freq[j] < minFreq || (freq[j] == minFreq && time[j] < time[pos])) {
                    minFreq = freq[j];
                    pos = j;
                }
            }
            
            frame[pos] = pages[i]; // Replace the page
            freq[pos] = 1;         // Reset frequency
            time[pos] = i;         // Update the last usage time
            faults++;
        }
        
        // Display the current state of frames
        printf("\nFrames: ");
        for (k = 0; k < frames; ++k) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
    }
    
    printf("\n\nTotal Page Faults = %d\n", faults);
    
    return 0;
}