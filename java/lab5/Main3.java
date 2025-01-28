package lab5;
import java.util.*;

public class Main3 extends Move {

    @Override
    public int countFrontMoves(int[] array) {
        int n = array.length;
        int[] sortedArray = array.clone();
        Arrays.sort(sortedArray);

        int longestSortedPrefix = 0;
        for (int i = 0; i < n; i++) {
            if (array[i] == sortedArray[longestSortedPrefix]) {
                longestSortedPrefix++;
            }
        }
        return n - longestSortedPrefix;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        Main3 main = new Main3();
        int result = main.countFrontMoves(array);
        System.out.println(result);

        scanner.close();
    }
}
