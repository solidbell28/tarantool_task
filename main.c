#include <stdlib.h>
#include <stdio.h>

enum {
    COMMON_SIZE = 10  // common number of elements to initialize an array
};

/*
 * Function that implements an algorithm for solving the presented problem
 * Parameters: landscape - array with data provided to the program; size - amount of elements provided
 * Returns the answer to the task
 *
 * The idea of solution is to count for each height (from 1 to maximum) the number of blocks
 * between the leftmost and the rightmost point with the curtain height and then to subtract
 * the overall amount of blocks of land because they were not taken into account during
 * the previous calculations
 */
int sea_volume(const int *landscape, size_t size) {
    int land_volume = 0;       // sum of land heights
    int max_height = INT_MIN;  // maximum height of land

    // calculating land_volume and max_height
    for (size_t i = 0; i < size; ++i) {
        int cur_height = landscape[i];
        land_volume += cur_height;
        if (cur_height > max_height) {
            max_height = cur_height;
        }
    }

    int water_volume = 0;     // preliminary result
    int left = 0, right = (int) size - 1;  // pointers to leftmost and rightmost points with certain height

    for (int height = 1; height <= max_height; ++height) {
        // finding the leftmost suitable point
        while (landscape[left] < height) {
            ++left;
        }

        // finding the rightmost suitable point
        while (landscape[right] < height) {
            --right;
        }

        // adding volume without considering land heights between left and right
        water_volume += right - left + 1;
    }

    // removing excess volume
    return water_volume - land_volume;
}

int main(void) {
    int *data = calloc(COMMON_SIZE, sizeof(data[0]));
    // exiting the program if an error occurred during memory allocation
    if (data == NULL) {
        printf(stderr, "Failed to allocate enough memory!\n");
        return 1;
    }
    int cur_size = COMMON_SIZE;  // current size of the array
    int i = 0;  // pointer to the first empty element of the array
    int num;

    // reading elements while it is possible
    while (scanf("%d", &num) == 1) {
        // increasing the array size by 2 times if space is over
        if (i == cur_size) {
            cur_size *= 2;
            data = realloc(data, cur_size * sizeof(data[0]));
            // exiting the program if an error occurred during memory allocation
            if (data == NULL) {
                printf(stderr, "Failed to allocate enough memory!\n");
                return 1;
            }
        }
        // adding new element to the array
        data[i] = num;
        ++i;
    }

    // printing result
    printf("%d\n", sea_volume(data, i));

    return 0;
}