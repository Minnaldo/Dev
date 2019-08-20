package ws_java_0820;

import java.sql.*;

public class WS0820 {

    private static Connection conn;
    private static PreparedStatement pst;
    private static Statement st;
    private static ResultSet rs;

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/WS0820?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");

            System.out.println("#1");
            num1(); // 1
            System.out.println("\n#2");
            num2(); // 2
            System.out.println("\n#3");
            num3(); // 3
            System.out.println("\n#4");
            num4(); // 4
            System.out.println("\n#5");
            num5(); // 5
            System.out.println("#6");
            num6(); // 6
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }

    }

    static void init() throws SQLException {
        st = conn.createStatement();
        String sql = "drop table author";
        st.execute(sql);
    }

    static void num1() throws SQLException {
        st = conn.createStatement();
        String sql = "CREATE TABLE author (authorno INT(2) PRIMARY KEY, name VARCHAR(50), phone VARCHAR(30))";
        st.execute(sql);

        sql = "insert into author(authorno, name, phone) values(10, '김태희','01000001000')\n" +
                "insert into author(authorno, name, phone) values(20, '이태희','01000003100')\n" +
                "insert into author(authorno, name, phone) values(30, '박태희','01009000000')\n" +
                "insert into author(authorno, name, phone) values(40, '최태희','01000004400')";
        st = conn.createStatement();
        st.execute(sql);
    }

    // book table을 수정
    static void num2() throws SQLException {
        st = conn.createStatement();
        String sql = "alter table book add foreign key (authorno) references author(authorno)";
        st.execute(sql);
    }

    // Book과 Author 테이블을 Join하여 도서명, 가격, 저자명을 검색하세요
    static void num3() throws SQLException {
        st = conn.createStatement();
        String sql = "SELECT a.title, a.price, b.name FROM book a, author b where a.authorno = b.authorno";
        rs = st.executeQuery(sql);
        StringBuilder sb = new StringBuilder();
        while (rs.next()) {
            sb.append(rs.getString("a.title") + " ");
            sb.append(rs.getString("a.price") + " ");
            sb.append(rs.getString("b.name"));
            System.out.println(sb.toString());
            sb.setLength(0);
        }
    }

    // 이름이 '김태희'인 저자의 도서명, isbn, 출판사를 출력하세요
    static void num4() throws SQLException {
        String sql = "SELECT a.title, a.isbn, a.publisher FROM book a WHERE a.authorno = (select authorno from author where name='김태희');";
        st = conn.prepareStatement(sql);
        rs = st.executeQuery(sql);

        StringBuilder sb = new StringBuilder();
        while (rs.next()) {
            sb.append(rs.getString("a.title") + " ");
            sb.append(rs.getString("a.isbn") + " ");
            sb.append(rs.getString("a.publisher"));
            System.out.println(sb.toString());
            sb.setLength(0);
        }
    }

    // author 테이블에 있는 저자명 별로 출간된 도서들을 도서명, 출판사, 가격, 저자명을 출력하라
    static void num5() throws SQLException {
        String sql = "SELECT a.title, a.publisher, a.price, name FROM book a INNER JOIN author b on (a.authorno = b.authorno) ORDER BY name";
        st = conn.createStatement();
        rs = st.executeQuery(sql);

        StringBuilder sb = new StringBuilder();
        while (rs.next()) {
            sb.append(rs.getString("a.title") + " ");
            sb.append(rs.getString("a.publisher") + " ");
            sb.append(rs.getInt("a.price") + " ");
            sb.append(rs.getString("b.name"));
            System.out.println(sb.toString());
            sb.setLength(0);
        }

    }

    static void num6() throws SQLException {
        String sql = "SELECT CONCAT(title,'은 ',publisher,'에서 출판했다') AS result FROM book;";
        st = conn.createStatement();
        rs = st.executeQuery(sql);

        while (rs.next()) {
            System.out.println(rs.getString("result"));
        }
    }
}
