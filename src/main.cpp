#include "common.h"
#include "BaseProcessor.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    char* pathToImage = argv[1];
    char* command = argv[2];

    BaseProcessor* proc = NULL;
    argv_t kwargs;

    if (strcmp(command, COMMAND_MEAN_FILTER_GRAYSCALE) == 0) {

    }
    else if (strcmp(command, COMMAND_MEAN_FILTER_RGB) == 0) {

    }
    else if (strcmp(command, COMMAND_MEDIAN_FILTER_GRAYSCALE) == 0) {

    }
    else if (strcmp(command, COMMAND_MEDIAN_FILTER_RGB) == 0) {

    }
    else if (strcmp(command, COMMAND_GAUSSIAN_FILTER_GRAYSCALE) == 0) {

    }
    else if (strcmp(command, COMMAND_GAUSSIAN_FILTER_RGB) == 0) {

    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
    proc->execute(kwargs);
    delete proc;
    return 0;
}

