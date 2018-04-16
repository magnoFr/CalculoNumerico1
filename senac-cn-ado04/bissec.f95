PROGRAM NEWTON
    IMPLICIT NONE
    REAL :: p
    REAL :: a
    REAL :: b, fc, c
    REAL :: error = 0.00000001
    INTEGER :: i
    READ*, p 
    b = p
    DO WHILE (i < 40)
        c = (a+b)/2
        fc = (c*c) - p
    
        IF(abs((b - a)/2) < error .OR. fc == 0) THEN
            EXIT
        END IF

        IF (fc.gt.0) THEN
            b = c
        ELSE
            a = c
        END IF

        i = i + 1
    END DO
    PRINT*, c
END PROGRAM NEWTON