# Write your MySQL query statement below
Select project_id , ROUND(SUM(Employee.experience_years)/COUNT(Project.employee_id),2) as average_years
from Project
JOIN Employee
ON Project.employee_id = Employee.employee_id
Group by project_id;