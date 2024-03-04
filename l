#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <regex>

#include <iostream>
#include <cstring>
#include <fstream>

#include <vector>

using namespace std;

void copyFile (char* name, char* nameNew) {
        size_t sizeOfBuf = 3;
        char* buffer = new char[sizeOfBuf];
        ifstream fin;
        fin.open(name, ios::binary);
        if (!fin.is_open()) {
                cout << "File not found!\n";
                return;
        }
        ofstream fout;
        fout.open(nameNew, ios::binary);
        while (!fin.eof()) {
                fin.read(buffer, sizeOfBuf);
                if (fin.gcount()) {
                        fout.write(buffer, fin.gcount());
                }
        }
        delete[] buffer;
        fin.close();
        fout.close();
        cout << "Successfully!\n";
}

void last_5(char* name) {
        ifstream file;
        file.open(name);
        int i = 0;
        string s;
        while (!file.eof()) {
                getline(file,s);
                ++i;
        }
        file.close();

        int count = i;
        file.open(name);
        i = 0;
        while (!file.eof()) {
                getline(file, s);
                if (i > count - 7) {
                        cout << s << '\n';
                }
                ++i;
        }
        file.close();
}
int moveFile (char* name, char* nameDir) {
        ifstream file;
        file.open(name, ios::binary);
        if (!file.is_open()) {
                return 1;
        }
        file.close();
        char* dirToMove = new char[strlen(name) + strlen(nameDir)];
        strcat(dirToMove, nameDir);
        strcat(dirToMove, "/");
        strcat(dirToMove, name);
        strcat(dirToMove, "\0");
        return rename(name, dirToMove);
}

void infoForFile (char* name) {
        struct stat buffer;
        if (lstat(name, &buffer) < 0) {
                cout << "Error\n";
        }
        else {
                cout << "File: " << name << "\n";
                cout << "Last modification:" << ctime(&buffer.st_mtime);
                cout << "Last access:" << ctime(&buffer.st_atime);
                cout << "Last state change:" << ctime(&buffer.st_ctime);
                cout << "File type: ";
                if (S_ISREG(buffer.st_mode)) {
                        cout << "regular\n";
                }
                else if (S_ISDIR(buffer.st_mode)) {
                        cout << "directory\n";
                }
                else if (S_ISBLK(buffer.st_mode)) {
                        cout << "block special\n";
                }
                else if (S_ISFIFO(buffer.st_mode)) {
                        cout << "pipe or FIFO\n";
                }
                else if (S_ISLNK(buffer.st_mode)) {
                        cout << "symbolic link\n";
                }
                else if (S_ISCHR(buffer.st_mode)) {
                        cout << "character special\n";
                }
                else if (S_ISSOCK(buffer.st_mode)) {
                        cout << "socket\n";
                }
                else {
                        cout << "unknown type\n";
                }

                cout << "File mode: ";
string mode;
                mode += (buffer.st_mode & S_IRUSR) ? "r" : "-";
                mode += (buffer.st_mode & S_IWUSR) ? "w" : "-";
                mode += (buffer.st_mode & S_IXUSR) ? "x" : "-";
                mode += (buffer.st_mode & S_IRGRP) ? "r" : "-";
                mode += (buffer.st_mode & S_IWGRP) ? "w" : "-";
                mode += (buffer.st_mode & S_IXGRP) ? "x" : "-";
                mode += (buffer.st_mode & S_IROTH) ? "r" : "-";
                mode += (buffer.st_mode & S_IWOTH) ? "w" : "-";
                mode += (buffer.st_mode & S_IXOTH) ? "x" : "-";
                cout << mode << "\n";
                cout << "Size: " << buffer.st_size << " bytes\n";
                cout << "User ID of owner: " << buffer.st_uid << "\n";
                cout << "Group ID of owner: " << buffer.st_gid << "\n";
                cout << "Devise ID: " << buffer.st_rdev << "\n";
        }
}

int get_code(string mask);
void chageRigtsOfFile(char* name, char* mode) {
        ifstream file;
        file.open(name, ios::binary);
        if (!file.is_open()) {
                cout << "Error, file not found!\n";
        }
        else {
                const regex reg3("([0-7])([0-7])([0-7])");
                  const regex reg9("(r|-)(w|-)(x|-)(r|-)(w|-)(x|-)(r|-)(w|-)(x|-)");
                if (regex_match(mode, reg3)) {
                        string samples[] = {"---","--x","-w-","-wx","r--","r-x"};
                        int mask = stoi(mode);
                        string ans;
                        while (mask != 0) {
                                ans = samples[mask % 10] + ans;
                                mask /= 10;
                        }
                        int code = get_code(ans);
                        chmod(name, code);
                        cout << "Successfully!\n";
                }
                else if (regex_match(mode, reg9)) {
                        int code = get_code(mode);
                        chmod(name, code);
                        cout << "Successfully!\n";
                }
                else {
                        cout << "Error format input!\n";
                }
        }
}
int get_code(string mask) {
        int ans = 0;
        int x = 256;
        for (int i = 0; i < mask.length(); ++i) {
                if (mask[i] != '-') {
                        ans += x;
                }
                x /= 2;
        }
        return ans;
}

int main (int argc, char* argv[]) {
        if (argc > 1) {
                last_5(argv[2]);
                if (strcmp(argv[1], "--help") == 0) {
                        cout << "Enter: ./final [--option]\n";
                        cout << "Options:\n";
                        cout << "--copy [FILE] [DIR] copy FILE to DIR\n";
                        cout << "--move [FILE] [DIR] move FILE to DIR\n";
                        cout << "--info [FILE] get info about FILE\n";
                        cout << "--chmod [FILE] [MODE] change mode of FILE to M\n";
                        cout << "[MODE] = [XXX where X from 0 to 7] | [rwxrwxrw]";

                }
                else if (strcmp(argv[1], "--copy") == 0 && argc == 4) {
                        copyFile(argv[2], argv[3]);
                }
                else if (strcmp(argv[1], "--move") == 0 && argc == 4) {
                        moveFile(argv[2], argv[3]);
                        cout << "Successfully!\n";
                }
                else if (strcmp(argv[1], "--info") == 0 && argc == 3) {
                        infoForFile(argv[2]);
                }
                else if (strcmp(argv[1], "--chmod") == 0 && argc == 4) {
                        chageRigtsOfFile(argv[2], argv[3]);
                } else {
                        cout << "enter ./final --help for requirements\n";
                }
        } else {
                cout << "enter ./final --help for requirements\n";
        }
        return 0;
}
