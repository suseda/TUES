import java.util.Map;

public class Request
{
    String path,body,method;
    Map<String,String> headers;


    public Request(String path, String body, String method, Map<String, String> headers)
    {
        this.path = path;
        this.body = body;
        this.method = method;
        this.headers = headers;
    }


}
