function convert() {
        let x = document.getElementById("num").value;
        x = parseFloat(x);

        // Get the 'from' and 'to' currency values
        let from = document.getElementById("from").value;
        let to = document.getElementById("to").value;

        // Perform the conversion
        let result;
        if (from === "1") {
            if(to === "2"){
                result = x * 0.012;
            }

            else{
                result = x;
            }

        }
        
        else if (from === "2") {
            if(to === "1"){
                result = x * 83.68;
            }

            else{
                result = x;
            }

        }
        
        else {
            result = "Invalid";
        }

        // Display the result
        document.getElementById("result").innerHTML = "Result: " + result;
    }