public class MultilineLinePerformance {

    public static void parseMultilineStringUsingJava11LineFunction(String multiline, int iterations) 
    {
        for(int i = 0; i < iterations; ++i) {

            multiline.lines()
            .map(line -> "// " + line);
            //.forEach(System.out::println);  printing takes time 
        }
    }

    public static void parseMultilineStringUsingBruteForce(String multiline, int iterations) 
    {
        int j = 0;
        String line = "// ";

        for(int i = 0; i < iterations; ++i)
        {
            while(j < multiline.length())
            {
                if(multiline.charAt(j) != '\n')
                {
                    line += multiline.charAt(j);
                }
                else
                {
                    //System.out.println(line); printing takes time
                    line = "// ";
                }
                ++j;
            }
        }
    }

    public static void main(String[] args) {

        var multiline = "This\r\nis a\r\nmultiline\r\nstring";
        var convertNanoToMilli = 1000000;
        var iterations = 100;

        long startTime = System.nanoTime();   
        parseMultilineStringUsingJava11LineFunction(multiline, iterations); 
        long estimatedTime = System.nanoTime() - startTime;

        System.out.println("Java 11's line method took " + estimatedTime / convertNanoToMilli
            + "milliseconds to run " + iterations + " times!");

        startTime = System.nanoTime();    
        parseMultilineStringUsingBruteForce(multiline, iterations);
        estimatedTime = System.nanoTime() - startTime;
        System.out.println("My brute force method took " + estimatedTime / convertNanoToMilli
            + "milliseconds to run " + iterations + " times!");
        // OUTPUT:

        // This
        // is a
        // multiline
        // string
    }
}