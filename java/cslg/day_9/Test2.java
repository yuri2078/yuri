package cslg.day_9;

abstract class Account {
    protected double balance;

    public Account(double init_balance) {
        balance = init_balance;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double add_balance) {
        balance += add_balance;
    }

    abstract boolean withdraw(double sub_balance);

    abstract void show();
}

class SavingsAccount extends Account {
    double interestRate;

    SavingsAccount(double balance, double interest_rate) {
        super(balance);
        interestRate = interest_rate;
    }

    boolean withdraw(double sub_balance) {
        if (balance < sub_balance) {
            System.out.printf("Withdraw %.2f false\n",sub_balance);
            return false;
        }
        balance -= sub_balance;
        System.out.printf("Withdraw %.2f true\n",sub_balance);
        return true;
    }

    void show() {
        System.out.printf("SavingAccount: Current balance is %.1f" , balance);
        System.out.printf(" Interest rate= %.2f\n", interestRate);
    }

    double getInterestRate() {
        return interestRate;
    }

}

class CheckingAccount extends Account {
    double overdraftProtection;

    CheckingAccount(double balance) {
        super(balance);
    }

    CheckingAccount(double balance, double overdraftProtection) {
        super(balance);
        this.overdraftProtection = overdraftProtection;
    }

    boolean withdraw(double sub_balance) {
        if (sub_balance > balance + overdraftProtection) {
            System.out.printf("Withdraw %.2f false\n",sub_balance);
            return false;
        }

        double over = sub_balance - balance;
        if (over > 0) {
            balance = 0;
            overdraftProtection -= over;
        } else {
            balance -= sub_balance;
        }
        System.out.printf("Withdraw %.2f true\n",sub_balance);
        return true;
    }

    void show() {
        System.out.printf("CheckingAccount: Current balance is %.1f" , balance);
        System.out.printf(" OverdraftProtection= %.1f\n" , overdraftProtection);
    }

    double getOverdraftProtection() {
        return overdraftProtection;
    }

}

class Customer {
    private String firstName;
    private String lastName;
    private int numberOfAccount = 0;

    private Account accounts[] = new Account[20];

    public Customer(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getNumOfAccount(){
        return numberOfAccount;
    }

    public void addAccount(Account account) {
        accounts[numberOfAccount++] = account;
    }

    public Account getAccount(int val) {
        return accounts[val];
    }
}

class Bank {
    Customer customers[];
    int numberOfCustomers;

    public Bank() {
        customers = new Customer[20];
        numberOfCustomers = 0;
    }

    public void addCustomer(String firstName, String lastName) {
        if (numberOfCustomers < 20) {
            customers[numberOfCustomers++] = new Customer(firstName, lastName);
        }
    }

    public int getNumOfCustomers() {
        return numberOfCustomers;
    }

    public Customer getCustomer(int number) {
        if (number >= numberOfCustomers) {
            return new Customer(null, null);
        }
        return customers[number];
    }
}

public class Test2 {
    static void testCustomer(Bank bank, int id) {
        System.out.println();
        System.out.printf("Testing account of customer No.%d...\n", id + 1);
        Customer customer = bank.getCustomer(id);
        for (int j = 0; j < customer.getNumOfAccount(); j++) {
            Account account = customer.getAccount(j);
            account.withdraw(300);
            account.withdraw(300);
            System.out.printf("Balance of account NO.%d is %.1f\n", j + 1, account.getBalance());
        }
    }

    static void showCustomers(Bank bank){
        System.out.println("Customer Reports");
        System.out.println("=============================");
        for (int i = 0; i < bank.getNumOfCustomers(); i++) {
            Customer customer = bank.getCustomer(i);
            System.out.printf("Customer:%s %s\n", customer.getFirstName(), customer.getLastName());
            for (int j = 0; j < customer.getNumOfAccount(); j++) {
                customer.getAccount(j).show();
            }
        }
    }
    public static void main(String[] args) {
        Bank bank = new Bank();
        // 添加客户
        bank.addCustomer("Simms", "Jane");
        bank.addCustomer("Bryant", "Owen");
        bank.addCustomer("Soley", "Tim");
        bank.addCustomer("Soley", "Maria");

        // 添加账号
        bank.getCustomer(0).addAccount(new SavingsAccount(500, 0.03));
        bank.getCustomer(0).addAccount(new CheckingAccount(500, 0));
        bank.getCustomer(0).addAccount(new CheckingAccount(500, 500));

        bank.getCustomer(1).addAccount(new CheckingAccount(200, 0));

        bank.getCustomer(2).addAccount(new SavingsAccount(1500, 0.03));
        bank.getCustomer(2).addAccount(new CheckingAccount(200, 0));

        bank.getCustomer(3).addAccount(new CheckingAccount(200, 0));
        bank.getCustomer(3).addAccount(new SavingsAccount(150, 0.03));

        // 测试
        showCustomers(bank);
        testCustomer(bank, 0);
    }
}