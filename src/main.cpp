#include "common.h"
#include "BaseProcessor.h"
#include "Smoother.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    char* pathToImage = argv[1];
    char* command = argv[2];

    BaseProcessor* proc = new Smoother(pathToImage);
    argv_t kwargs;

    if (strcmp(command, COMMAND_MEAN_FILTER_GRAYSCALE) == 0) {
        kwargs["filter"] = MEAN_FILTER_LABEL;
        kwargs["kernel_size"] = argv[3];
    }
    else if (strcmp(command, COMMAND_MEAN_FILTER_RGB) == 0) {
        kwargs["filter"] = MEAN_FILTER_LABEL;
        kwargs["kernel_size"] = argv[3];
    }
    else if (strcmp(command, COMMAND_MEDIAN_FILTER_GRAYSCALE) == 0) {
        kwargs["filter"] = MEDIAN_FILTER_LABEL;
        kwargs["kernel_size"] = argv[3];
    }
    else if (strcmp(command, COMMAND_MEDIAN_FILTER_RGB) == 0) {
        kwargs["filter"] = MEDIAN_FILTER_LABEL;
        kwargs["kernel_size"] = argv[3];
    }
    else if (strcmp(command, COMMAND_GAUSSIAN_FILTER_GRAYSCALE) == 0) {
        kwargs["filter"] = GAUSSIAN_FILTER_LABEL;
        kwargs["kernel_size"] = argv[3];
    }
    else if (strcmp(command, COMMAND_GAUSSIAN_FILTER_RGB) == 0) {
        kwargs["filter"] = GAUSSIAN_FILTER_LABEL;
        kwargs["kernel_size"] = argv[3];
    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
    proc->execute(kwargs);
    delete proc;
    return 0;
}

