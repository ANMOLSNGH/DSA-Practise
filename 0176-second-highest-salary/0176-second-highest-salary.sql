# Write your MySQL query statement below
/*Select (
    select distinct salary
    from Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) As SecondHighestSalary;
# O(NLOGN) space O(N)
*/

SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);



