#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    char curr, prev = 1;

    if (argc < 2) {
        cerr << "File path is missing" << endl;
        return 1;
    }

    ifstream source(argv[1], ios_base::binary);
    if (!source.good()) {
        cerr << "Error while opening the file" << endl;
        return 1;
    }
    while (source.get(curr)) {
        if (isprint(curr))
            cout << curr;
        else if ((prev == 0) && curr)
            cout << endl;
        prev = curr;
    }
    source.close();

    return 0;
}
