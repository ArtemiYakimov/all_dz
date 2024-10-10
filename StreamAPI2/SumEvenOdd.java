import java.util.Arrays;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class SumEvenOdd {
    public static void main(String[] args) throws Exception {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        ExecutorService executor = Executors.newFixedThreadPool(2);

        Future<Integer> evenSumFuture = executor.submit(() ->
                numbers.stream()
                        .filter(n -> n % 2 == 0)
                        .mapToInt(Integer::intValue)
                        .sum()
        );

        Future<Integer> oddSumFuture = executor.submit(() ->
                numbers.stream()
                        .filter(n -> n % 2 != 0)
                        .mapToInt(Integer::intValue)
                        .sum()
        );

        int evenSum = evenSumFuture.get();
        int oddSum = oddSumFuture.get();

        executor.shutdown();

        System.out.println("Сумма четных чисел: " + evenSum);
        System.out.println("Сумма нечетных чисел: " + oddSum);
    }
}
