import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Player implements Runnable {
    private String name;

    public Player(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println(name + " is playing turn " + i);
                Thread.sleep(1000); 
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Game {
    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(2); 

        Player player1 = new Player("Player 1");
        Player player2 = new Player("Player 2");

        executorService.execute(player1);
        executorService.execute(player2);

        executorService.shutdown();
    }
}
