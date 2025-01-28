 function find() {
            let string = document.getElementById("string").value.trim(); //used to remove extra spaces added unintentionally at the end and beginning of input

            let words = string.split(/\s+/); // Split by whitespace
            let smallest = words[0];
            let largest = words[0];

            for (let word of words) {
                if (word.length < smallest.length) {
                    smallest = word;
                }
                if (word.length > largest.length) {
                    largest = word;
                }
            }

            document.getElementById("smallest").value = smallest;
            document.getElementById("largest").value = largest;
        }
