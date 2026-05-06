-- Test data
CREATE TABLE STUDENT (
    ID INT,
    NAME VARCHAR(50),
    SCORE FLOAT
);

INSERT INTO STUDENT VALUES 
(1, 'Bob', 50.0),
(2, 'John', 65.5),
(3, 'Harry', 45.0),
(4, 'Dick', 85.0),
(5, 'Dev', 25.0),
(6, 'Sid', 98.0),
(7, 'Tom', 90.0),
(8, 'Julia', 70.5),
(9, 'Erica', 81.0),
(10, 'Jerry', 85.0);

-- Run your solution
SELECT ID, NAME
FROM STUDENT
ORDER BY SCORE DESC, ID ASC
LIMIT 3;

-- Expected: 6|Sid, 7|Tom, 4|Dick