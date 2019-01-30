#include "fstream"
#include "string"

template <typename T>
class file_info
{
  private:
    string file_name;
    string file_type;
    string fie_dir;
    int file_size;
    ifstream ifs;

  public:
    file_info()
    {
    }

    // 기본 경로는 현재 디렉터리를 기본으로 한다
    file_info(string dir = "./")
    {
        this.file_dir = dir;
    }

    int getFileSize()
    {
        if (!file_opend)
        {
            // file is not opend
            this.ifs.open(getFullPath, ios::binary);
            if (ifs.is_open())
            {
                this.file_opend = true;

                ifs.seekg(0, ios::end);
                file_size = ifs.tellg();
                return file_size;
            }
        }
        else
        {
            // Error occured
            cout << "the file have opend, plz close first\n";
            exit(1);
        }

    }

    string getFullPath()
    {
        return this.file_dir + this.filename + "." + this.file_type;
    }
}
