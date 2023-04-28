package cslg.day_10;

import java.util.InputMismatchException;
import java.util.Scanner;

class Student {
    private String name;
    private int age;

    Student(String name, int age) throws StudentException {
        this.name = name;
        this.age = age;
        if (name == null || name.isEmpty() || name.equals(" ")) {
            throw new StudentException("name null");
        }

        if (age < 6 || age > 100) {
            throw new StudentException("age error");
        }
    }

    public void setAge(int age) throws StudentException {
        this.age = age;
        if (age < 6 || age > 100) {
            throw new StudentException("update age error");
        }
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }
}

class StudentException extends Exception {
    String error;

    StudentException(String error) {
        this.error = error;
    }

    public String getMessage() {
        return error;
    }
}

public class Test2 {
    private static Scanner reader;
    public static void main(String[] args) {
        int age;
        String name;
        Student stu = null;
        try {
            reader = new Scanner(System.in);
            name = reader.nextLine();
            age = reader.nextInt();
            stu = new Student(name, age);
            System.out.println("student:" + stu.getName() + "," + stu.getAge());
            age = reader.nextInt();
            stu.setAge(age);
            System.out.println("student:" + stu.getName() + "," + stu.getAge());
        } catch (InputMismatchException e) {
            System.out.println("format error");
        } catch (StudentException se) {
            System.out.println(se.getMessage());
        }
    }
}
