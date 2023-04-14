package cslg.day_8;

class Account {
    private double balance;

    public Account(double init_balance) {
        balance = init_balance;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double add_balance) {
        balance += add_balance;
    }

    public void withdraw(double sub_balance) {
        balance -= sub_balance;
    }
}

class Customer {
    private String firstName;
    private String lastName;
    private Account account;

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

    public void setAccount(Account account) {
        this.account = account;
    }

    public Account getAccount() {
        return account;
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

public class Test4 {
    public static void main(String[] args) {
        Bank bank = new Bank();

        bank.addCustomer("Simms", "Jane");

        bank.addCustomer("Bryant", "Owen");

        bank.addCustomer("Soley", "Tim");

        bank.addCustomer("Soley", "Maria");

        bank.getCustomer(0).setAccount(new Account(500));

        bank.getCustomer(1).setAccount(new Account(500));

        bank.getCustomer(2).setAccount(new Account(500));

        bank.getCustomer(3).setAccount(new Account(500));

        for (int i = 0; i < bank.getNumOfCustomers(); i++) {

            Customer c = bank.getCustomer(i);

            System.out.println("Customer [" + (i + 1) + "] is " + c.getFirstName() + "," + c.getLastName());

        }

        System.out.println("\nTesting Customer's Account ...");

        Customer c = bank.getCustomer(0);

        Account acct = c.getAccount();

        System.out.println("Withdraw 150.00");

        acct.withdraw(150);

        System.out.println("Deposit 22.50");

        acct.deposit(22.50);

        System.out.println("Withdraw 47.62");

        acct.withdraw(47.62);

        System.out.println(
                "Customer [" + c.getFirstName() + "," + c.getLastName() + "] has a balance of " + acct.getBalance());
    }
}
