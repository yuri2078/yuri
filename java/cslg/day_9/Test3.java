package cslg.day_9;

abstract class Aves {
    private String feeds;
    private final String type = "Aves";

    Aves(String feeds) {
        this.feeds = feeds;
    }

    public String getFeeds() {
        return feeds;
    }

    public String getType() {
        return type;
    }

    public abstract void eggs();
}

abstract class Insect {
    private String bahaviour;
    private final String type = "Insect";

    Insect(String bahaviour) {
        this.bahaviour = bahaviour;
    }

    public abstract void oviposit();

    public String getBahaviour() {
        return bahaviour;
    }

    public String getType() {
        return type;
    }

}

interface FlyAnimal {
    public void fly();
}

class Swallow extends Aves implements FlyAnimal {
    Swallow() {
        super("eat insects");
    }

    public void fly() {
        System.out.println("Swallow can fly.");
    }

    public void eggs() {
        System.out.println("Swallow lay eggs. ");
    }

    public void printInfo() {
        System.out.printf("Swallow: %s, %s\n", getType(), getFeeds());
    }
}

class Mosquitoes extends Insect implements FlyAnimal {
    Mosquitoes() {
        super("pest");
    }

    public void fly() {
        System.out.println("Mosquitoes can fly.");
    }

    public void oviposit() {
        System.out.println("Mosquitoes oviposit.");
    }

    public void printInfo() {
        System.out.printf("Mosquitoes: %s, %s\n", getType(), getBahaviour());
    }

}

public class Test3 {
    public static void main(String[] args) {
        Swallow s = new Swallow();

        Mosquitoes m = new Mosquitoes();
        s.printInfo();
        s.fly();
        s.eggs();
        m.printInfo();
        m.fly();
        m.oviposit();
    }
}
