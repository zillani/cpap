
#ifndef CPP_SNIPPETS_DAO_H
#define CPP_SNIPPETS_DAO_H

#endif

#include <cstdlib>
#include <iostream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>

using namespace std;
using namespace sql;
namespace Cpap {
    namespace Dao {
        class Sql {
        public:
            static int connect() {
                try {
                    sql::Driver *driver;
                    sql::Connection *con;

                    cout << "connecting to mysql server....";
                    driver = get_driver_instance();
                    con = driver->connect("tcp://127.0.0.1:3306", "zillani", "root");
                    cout << "connected" << endl;

                    delete con;

                } catch (sql::SQLException &e) {
                    cout << "# ERR: " << e.what();
                    cout << " (MySQL error code: " << e.getErrorCode();
                    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
                }
                cout << endl;
                return EXIT_SUCCESS;
            }
        };

    }
}