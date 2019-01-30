
/**
 * @param file_full_name : file name + type
 * @param size           : file size
 */


 // * 참조 : https://m.blog.naver.com/PostView.nhn?blogId=dash0215&logNo=110031770776&proxyReferer=https%3A%2F%2Fwww.google.com%2F (객체 직렬화를 통한 오브젝트 전송 in java)


public class file_info {

    private String file_full_name;
    private int size;

    public file_info(){}

    public file_info(String name, String type, String size) {
        this.file_full_name = name + "." + type;
        this.size = Integer.parseInt(size);
    }

    public String getFilename() {
        return this.file_full_name;
    }

    public int getSize() {
        return this.size;
    }
}