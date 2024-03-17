//
// Created by jlibyvali on 24-1-12.
//

/*
 * Cmake's support for c++20 modules still not finished since 24-2;
 */

#include <string>

namespace  Records{
    const int defaultSalary { 30'000 };
    const int defaultChangeAmount {1'000};
    class Employee;
}

class Records::Employee{

private:
     std::string m_firstName,m_lastName;
     int m_employeeNum {-1};
     int m_salary {30'000} ;
     bool m_hired {false} ;
public:
    // function for employee;
    Employee() = default;
    Employee(const std::string& firstname,const std::string& lastname);
    void promote(int raiseAmount = Records::defaultChangeAmount);
    void demote(int demeritAmount = Records::defaultChangeAmount);
    void hire();
    void fire();
    void display() const;

    // Getters and Setters
    const std::string &getMFirstName() const {
        return m_firstName;
    }

    void setMFirstName(const std::string &mFirstName) {
        m_firstName = mFirstName;
    }

    const std::string &getMLastName() const {
        return m_lastName;
    }

    void setMLastName(const std::string &mLastName) {
        m_lastName = mLastName;
    }

    int getMEmployeeNum() const {
        return m_employeeNum;
    }

    void setMEmployeeNum(int mEmployeeNum) {
        m_employeeNum = mEmployeeNum;
    }

    int getMSalary() const {
        return m_salary;
    }

    void setMSalary(int mSalary) {
        m_salary = mSalary;
    }

    bool isMHired() const {
        return m_hired;
    }

    void setMHired(bool mHired) {
        m_hired = mHired;
    }


};
