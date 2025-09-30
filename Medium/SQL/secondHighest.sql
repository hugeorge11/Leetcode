# Write your MySQL query statement below
# George Hu 9/30
# secondHighest.sql
# High time performance!
SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT salary FROM Employee
    WHERE salary != (SELECT MAX(salary) FROM Employee)
) AS SubQuery
