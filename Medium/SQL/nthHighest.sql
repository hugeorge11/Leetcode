CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT

BEGIN
set N=N-1;
  RETURN (
        
ifnull(
(
SELECT DISTINCT Salary FROM Employee
ORDER BY Salary desc
limit 1 offset N)
,null)
  );
END
