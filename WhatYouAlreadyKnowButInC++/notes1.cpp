What you should already know, but now in C++
    Comments in C++
        // single line
        /*
        multiline
        */
    Control Structures in C++
        * Sequence
        int x = 5;      // 1
        int y = 7;      // 2
        int z = x + y;  // 3
        
        * Selection / Branching / Conditionals
        if (condition) {
            // then do something if condition evaluates to true
        }
        // control resumes here

        if (condition) {
            // then
        } 
        else {
            // do something else if condition evaluates to false
        }
        // control resumes here

        if (condition_1) {
            // do if condition_1 evaluates to true
        } 
        else if (condition_2) {
            // do if condition_2 evaluates to true
        } 
        else if (condition_3) {

        } 
        ... 
        else {
            // do this if NONE of the conditions evaluate to true
        }
        // control resumes here

        switch (variable) {
            case value_1 : 
                // do this if variable == value_1
                break;
            case value_2 :
                // do this if variable == value_2
                break;
            ...
            default :
                // do this if NONE of the cases match
                break;
        }
        // control resumes here

        * Iteration / Repetition / Loops
        for (int i = 0; i < N; i++) {
            // do this N times
        }

        int i = 0;
        while (i < N) {
            // do this (N times)
            i++;
        }

        while (condition) {
            // do this until condtion evaluates to false
        }

        do {
            // do this (at least once) until condition evaluates to false
        } while (condition);

        for (int i = 0; i < N; i++) {
            // do this N times
            for (int j = 0; j < N; j++) {
                // do this N times (for N*N times total)
            }
        }

    Variables in C++
        * declaration
        // declares the type, but does not allocate the space

        * definition
        // allocates the space (only after declaration)
        int x;
        double y;
        char c;
        std::string s; 

        * initialization
        x = 1;
        y = 3.14;
        c = 'i';
        s = "howdy";

        float f = 6.28;

        * types
        // primitive
        int, float, short, char, long, double, unsigned, bool
        // defined
        std::string, std::ostream, MyObject, ...
        
        * integer overflow
        // char   8 bits   [-2^7, 2^7 - 1] = [-128, 127]
        // short 16 bits [-2^15, 2^15 - 1] = [-16384, 16383]
        // int   32 bits [-2^31, 2^31 - 1] = [-2147483648, 2147483647]
        // long  64 bits [-2^63, 2^63 - 1] = [-9223372036854775808, 9223372036854775807]
        char c = 127;
        c++;
        // c == -128 (value is not guaranteed to wrap around like this, value is undefined)