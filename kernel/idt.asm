.extern errorHandler

.macro isrError id
isrStub\id:
    call errorHandler
    iret
.endm

.macro isrNoError id
isrStub\id:
    call errorHandler
    iret
.endm

isrNoError 0
isrNoError 1
isrNoError 2
isrNoError 3
isrNoError 4
isrNoError 5
isrNoError 6
isrNoError 7
isrError 8
isrNoError 9
isrError 10
isrError 11
isrError 12
isrError 13
isrError 14
isrNoError 15
isrNoError 16
isrError 17
isrNoError 18
isrNoError 19
isrNoError 20
isrNoError 21
isrNoError 22
isrNoError 23
isrNoError 24
isrNoError 25
isrNoError 26
isrNoError 27
isrNoError 28
isrNoError 29
isrError 30
isrNoError 31

.global isrStubTable
isrStubTable:
    .int isrStub0
    .int isrStub1
    .int isrStub2
    .int isrStub3
    .int isrStub4
    .int isrStub5
    .int isrStub6
    .int isrStub7
    .int isrStub8
    .int isrStub9
    .int isrStub10
    .int isrStub11
    .int isrStub12
    .int isrStub13
    .int isrStub14
    .int isrStub15
    .int isrStub16
    .int isrStub17
    .int isrStub18
    .int isrStub19
    .int isrStub20
    .int isrStub21
    .int isrStub22
    .int isrStub23
    .int isrStub24
    .int isrStub25
    .int isrStub26
    .int isrStub27
    .int isrStub28
    .int isrStub29
    .int isrStub30
    .int isrStub31
