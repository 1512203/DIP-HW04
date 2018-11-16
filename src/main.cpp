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
        kwargs["grayscale"] = REQUIRE_GRAYSCALE;
        kwargs["filter"] = MEAN_FILTER_LABEL;
        kwargs["height"] = argv[3];
        if (argc >= 5) {
            kwargs["width"] = argv[4];
        }
    }
    else if (strcmp(command, COMMAND_MEAN_FILTER_RGB) == 0) {
        kwargs["grayscale"] = NOT_REQUIRE_GRAYSCALE;
        kwargs["filter"] = MEAN_FILTER_LABEL;
        kwargs["height"] = argv[3];
        if (argc >= 5) {
            kwargs["width"] = argv[4];
        }
    }
    else if (strcmp(command, COMMAND_MEDIAN_FILTER_GRAYSCALE) == 0) {
        kwargs["grayscale"] = REQUIRE_GRAYSCALE;
        kwargs["filter"] = MEDIAN_FILTER_LABEL;
        kwargs["height"] = argv[3];
        if (argc >= 5) {
            kwargs["width"] = argv[4];
        }
    }
    else if (strcmp(command, COMMAND_MEDIAN_FILTER_RGB) == 0) {
        kwargs["grayscale"] = NOT_REQUIRE_GRAYSCALE;
        kwargs["filter"] = MEDIAN_FILTER_LABEL;
        kwargs["height"] = argv[3];
        if (argc >= 5) {
            kwargs["width"] = argv[4];
        }
    }
    else if (strcmp(command, COMMAND_GAUSSIAN_FILTER_GRAYSCALE) == 0) {
        kwargs["grayscale"] = REQUIRE_GRAYSCALE;
        kwargs["filter"] = GAUSSIAN_FILTER_LABEL;
        kwargs["height"] = argv[3];
        if (argc >= 5) {
            kwargs["width"] = argv[4];
        }
    }
    else if (strcmp(command, COMMAND_GAUSSIAN_FILTER_RGB) == 0) {
        kwargs["grayscale"] = NOT_REQUIRE_GRAYSCALE;
        kwargs["filter"] = GAUSSIAN_FILTER_LABEL;
        kwargs["height"] = argv[3];
        if (argc >= 5) {
            kwargs["width"] = argv[4];
        }
    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }
    proc->execute(kwargs);
    delete proc;
    return 0;
}

