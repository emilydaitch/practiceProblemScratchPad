import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.IOException;
import java.nio.file.StandardOpenOption;
 
public class FileWriteMethodExample 
{
    public static void main(String[] args) 
    {
        Path filePath = Paths.get("C:/", "Users/User", "test.txt");
 
        try
        {
            //Write content to file
            Files.writeString(filePath, "Hello World1 !!\n", StandardOpenOption.APPEND);
 
            //Verify file content
            String content = Files.readString(filePath);
 
            System.out.println(content);
        } 
        catch (IOException e) 
        {
			System.out.println("No such file.");
			//e.printStackTrace();
			try {
				File myObj = new File("C:/Users/User/test.txt");
				if (myObj.createNewFile()) {
					System.out.println("File created: " + myObj.getName());
					
					//Write content to file
                    Files.writeString(filePath, "Hello World2 !!\n", StandardOpenOption.APPEND);
 
                    //Verify file content
                    String content = Files.readString(filePath);
 
                    System.out.println(content);
			    }
			} catch (IOException e2) {
				System.out.println("An error occurred.");
				e.printStackTrace();
				e2.printStackTrace();				
			}
        }
    }
}

//https://howtodoinjava.com/java11/write-string-to-file/
//https://docs.oracle.com/javase/7/docs/api/java/nio/file/Paths.html
//https://www.w3schools.com/java/java_files_create.asp