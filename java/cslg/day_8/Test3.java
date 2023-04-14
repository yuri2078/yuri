package cslg.day_8;

class Animal {
    private String name;
    private String food;
    private String sleepTime;
    private static String type;

    protected void eat() {
        System.out.println("I like eat " + food);
    }

    protected void sleep() {
        System.out.println("I sleep at " + sleepTime);
    }

    protected void showInfo() {
        System.out.println("I am " + type + " my name is " + name);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setFood(String food) {
        this.food = food;
    }

    public String getFood() {
        return food;
    }

    public void setSleepTime(String sleepTime) {
        this.sleepTime = sleepTime;
    }

    public String getSleepTime() {
        return sleepTime;
    }

    Animal() {
        System.out.println("--Animal--");
    }
}

class Tiger extends Animal {
    private String type = "Tiger";

    Tiger() {
        super();
        System.out.println("--Tiger--");
    }

    public void showInfo() {
        
        System.out.println("Tiger:I am " + type + ",my name is " + super.getName());
        // run();
    }

    public void run() {
        System.out.println("I like running.");
    }
}

class Panda extends Animal {
    private String type = "Panda";

    Panda() {
        super();
        System.out.println("--Panda--");
    }

    public void showInfo() {
        System.out.println("I am " + type + ",my name is " + super.getName());
        climbTree();
    }

    public void climbTree() {
        System.out.println("I like climing.");
    }
}

class Bat extends Animal {
    private String type = "Bat";

    Bat() {
        super();
        System.out.println("--Bat--");
    }

    public void showInfo() {
		System.out.println("I am " + type + ",my name is " + super.getName());
		fly();
	}

    public void fly(){
        System.out.println("I can fly.");
    }
}

public class Test3 {
    public static void main(String[] args) {
        Tiger tiger = new Tiger();
        Panda panda = new Panda();
        Bat bat = new Bat();

        tiger.setName("dandan");
        tiger.setFood("meat");
        tiger.setSleepTime("evening");

        panda.setName("xiaohei");
        panda.setFood("bamboo");
        panda.setSleepTime("day and night");

        bat.setName("shuaishuai");
        bat.setFood("insect");
        bat.setSleepTime("day");

        Animal animals[] = { tiger, panda, bat };
        for (Animal animal : animals) {
            animal.showInfo();
            animal.eat();
            animal.sleep();
        }
    }
    
}
