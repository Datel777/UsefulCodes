#include <iostream>

using namespace std;


class FileContent
{
    long _size;
    char *_data;

public:
    FileContent(const char *filename)
    {
        if (FILE *file = fopen(filename, "r"))
        {
            fseek(file, 0L, SEEK_END);
            _size = ftell(file);

            //rewind(file);
            fseek(file, 0L, SEEK_SET);

            if ((_data = static_cast<char*>(malloc(_size))))
            {
                fread(_data, sizeof(char), _size, file);
                fclose(file);
                return;
            }

            fclose(file);
        }

        _size = 0;
        _data = nullptr;
    }

    inline ~FileContent()           {if (_data) free(_data);}

    inline operator bool() const    {return _data;}

    inline long size() const        {return _size;}
    inline const char *data() const {return _data;}
};


int main()
{
    const char *filename = "Test.rar";

    if (FileContent content = FileContent(filename))
    {
        cout << "size of \"" << filename << "\" = " << content.size() << endl;
        cout << "data of \"" << filename << "\":\n" << content.data() << endl;
    } else
        cout << "could not open file \"" << filename << endl;

    return 0;
}
