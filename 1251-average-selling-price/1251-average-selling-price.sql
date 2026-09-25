# Write your MySQL query statement below
SELECT P.product_id,ROUND(COALESCE(SUM(P.price*U.units)/SUM(U.units),0),2) as average_price
from Prices P
LEFT JOIN UnitsSold U
ON P.product_id = U.product_id  AND U.purchase_date 
        BETWEEN P.start_date AND P.end_date
Group by P.product_id;