PROGRAM SECANTE
    IMPLICIT NONE
    REAL :: p
    REAL :: a
    REAL :: b, fc, c
    REAL :: error = 0.00000001
    INTEGER :: i
    READ*, p 
    b = p
    DO WHILE (i < 40)
        fc = ((a*( (b * b) - p)) - (b*( (a * a) - p)))/(( (b * b) - p) - ( (a * a) - p))
        
        a = b
        b = fc
        IF(abs((b - a)) < error .OR. fc == 0) THEN
            EXIT
        END IF
        i = i + 1
    END DO
    PRINT*, fc
END PROGRAM SECANTE