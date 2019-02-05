#include <iostream>
#include <mysql/mysql.h>

using namespace std;

template <typename T>
class dbInfo
{

  private:
    string server_addr;
    string user_name;
    string user_password;
    string db_name;
    MYSQL mysql;    // MYSQL : db와의 연결을 관리하는 구조체

  public:
    dbInfo(string server_addr, string user_name, string user_password, string db_name)
    {
        mysql_init(&this.mysql); // MYSQL 객체 초기화
    }

    // MYSQL과의 연결을 세팅하는 함수
    MYSQL *mysql_connection_setup()
    {
        // mysql에 연결이 실패했을경우 에러메시지 출력 및 프로그램 종료
        if (!mysql_real_connect(this.mysql, this.name, this, password, NULL, 0))
        {
            cout << mysql_error(this.mysql) << endl;
            exit(1);
        }
        else
        {
            cout << "DB Connect Complete" << endl;
        }
    }

    // MYSQL_RES // SELECT 등 결과를 리턴하는 query의 결과를 나타내는 자료형
    // MYSQL_ROW // MYSQL_RES에서 하나의 레코드씩 값을 얻어 올 때 쓰이는 자료형
    // MYSQL_FIELD // 필드의 이름과 필드의 타입 등 필드에 관한 정보를 저장하는 자료형
};

int main(int argc, char const *argv[])
{

    return 0;
}