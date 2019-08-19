package ws0819;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class BookDAO {

    private Connection conn;
    private ResultSet rs;
    private PreparedStatement st;

    public BookDAO() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/testDB?serverTimezone=UTC&useUniCode=yes&characterEncoding=UTF-8", "ssafy", "ssafy");
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void close(Connection connection) {
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void close(Statement statement) {
        if (st != null) {
            try {
                st.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void close(ResultSet resultSet) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public void insertBook(Book book) throws SQLException {
        String sql = "insert into book values(?, ?, ?, ?, ?, ?)";
        PreparedStatement st = conn.prepareStatement(sql);
        st.setString(1, book.getIsbn());
        st.setString(2, book.getTitle());
        st.setString(3, book.getAuthor());
        st.setString(4, book.getPublisher());
        st.setInt(5, book.getPrice());
        st.setString(6, book.getDescription());
        st.execute();
    }

    public void updateBook(Book book) throws SQLException {
        String sql = "update book set title =?, author = ?, publisher = ?, price=?, description=? where isbn = ?";
        st = conn.prepareStatement(sql);
        st.setString(5, book.getIsbn());
        st.setString(1, book.getTitle());
        st.setString(2, book.getAuthor());
        st.setString(3, book.getPublisher());
        st.setInt(5, book.getPrice());
        st.setString(4, book.getDescription());
        st.execute();
    }

    public void deleteBook(String isbn) throws SQLException {
        String sql = "delete from book where isbn=?";
        st = conn.prepareStatement(sql);
        st.setString(1, isbn);
        st.execute();
    }

    public Book findBook(String isbn) throws SQLException {
        String sql = "select * from book where isbn=?";
        st = conn.prepareStatement(sql);
        st.setString(1, isbn);
        rs = st.executeQuery();
        Book book = null;

        if (rs.next()) {
            book = new Book();
            book.setIsbn(rs.getString("isbn"));
            book.setIsbn(rs.getString("title"));
            book.setIsbn(rs.getString("author"));
            book.setIsbn(rs.getString("publisher"));
            book.setPrice(rs.getInt("price"));
            book.setIsbn(rs.getString("description"));
        }
        return book;
    }

    public List<Book> listBooks() throws SQLException {
        String sql = "select * from book";
        st = conn.prepareStatement(sql);
        rs = st.executeQuery();
        List<Book> list = new ArrayList<>();
        while (rs.next()) {
            list.add(new Book(rs.getString("isbn"), rs.getString("title"), rs.getString("author"),
                    rs.getString("publisher"), rs.getInt("price"), rs.getString("description")));
        }
        return list;
    }

    public int count() throws SQLException {
        String sql = "select count(isbn) from book";
        st = conn.prepareStatement(sql);
        rs = st.executeQuery();
        int cnt = 0;
        if (rs.next()) {
            cnt = rs.getInt(1);
        }
        return cnt;
    }
}
