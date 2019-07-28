package fri_project_2;

public class MovieMgr {
    private Movie[] movies;
    private int index;
    private int max;

    private static MovieMgr mm = new MovieMgr();

    public static MovieMgr getInstance() {
        return mm;
    }

    public MovieMgr() {
        this.index = 0;
        this.max = 100;
        this.movies = new Movie[100];
    }

    public void add(Movie m) {
        if (index < max) {
            movies[index++] = m;
        } else {
            // Array Doubling
            max *= 2;
            Movie[] tmp = new Movie[max];
            System.arraycopy(movies, 0, tmp, 0, movies.length);
            movies = tmp;
            movies[index++] = m;
        }
    }

    public Movie[] search() {
        int cnt = 0;
        for (int i = 0; i < index; i++) {
            if (movies[i] != null) {
                cnt++;
            }
        }
        int idx = 0;
        Movie[] tmp = new Movie[cnt];
        for (int i = 0; i < index; i++) {
            if (movies[i] != null) {
                tmp[idx] = movies[i];
                idx++;
            }
        }
        return tmp;
    }

    public Movie[] search(String title) {
        int cnt = 0;
        for (int i = 0; i < index; i++) {
            if (movies[i].getTitle().equals(title))
                cnt++;
        }
        int idx = 0;
        Movie[] tmp = new Movie[cnt];
        for (int i = 0; i < index; i++) {
            if (movies[i].getTitle().equals(title))
                tmp[idx++] = movies[i];
        }
        return tmp;
    }

    public Movie[] searchDirector(String name) {
        int cnt = 0;
        for (int i = 0; i < index; i++) {
            if (movies[i].getDirector().equals(name))
                cnt++;
        }
        int idx = 0;
        Movie[] tmp = new Movie[cnt];
        for (int i = 0; i < index; i++) {
            if (movies[i].getDirector().equals(name))
                tmp[idx++] = movies[i];
        }
        return tmp;
    }

    public Movie[] searchGenre(String genre) {
        int cnt = 0;
        for (int i = 0; i < index; i++) {
            if (movies[i].getGenre().equals(genre))
                cnt++;
        }
        int idx = 0;
        Movie[] tmp = new Movie[cnt];
        for (int i = 0; i < index; i++) {
            if (movies[i].getGenre().equals(genre))
                tmp[idx++] = movies[i];
        }
        return tmp;
    }

    public void delete(String title) {
        if (index > 0)
            for (int i = 0; i < index; i++) {
                if (movies[i].getTitle().equals(title)) {
                    movies[i] = movies[index--];
                    break;
                }
            }
        else {
            System.out.println("삭제할 데이터가 없습니다.");
        }
    }

    public int size() {
        return index;
    }


}
