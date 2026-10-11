# Write your MySQL query statement below
Select p.product_id , ROUND(COALESCE(SUM(p.price*u.units)/SUM(u.units),0),2) as average_price
from Prices p
LEFT JOIN UnitsSold u
ON u.product_id = p.product_id  AND u.purchase_date BETWEEN p.start_date AND p.end_date
Group BY u.product_id