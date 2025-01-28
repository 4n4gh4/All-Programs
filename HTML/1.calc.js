
    function calc() {
        // Get the input numbers
        let x = parseFloat(document.getElementById("num1").value);
        let y = parseFloat(document.getElementById("num2").value);

        // Convert the inputs to numbers before performing any operations


        // Get the selected operation
        let operation = document.querySelector('input[name="op"]:checked').value;

        // Perform the operation
        let result;
        if (operation === "1") {
            result = x + y;
        } else if (operation === "2") {
            result = x - y;
        } else if (operation === "3") {
            result = x * y;
        } else if (operation === "4") {
            if (y !== 0) {
                result = x / y;
            } else {
                result = "Cannot divide by zero";
            }
        } else {
            result = "Invalid operation";
        }

        // Display the result
        document.getElementById("result").innerHTML = "Result: " + result;
    }