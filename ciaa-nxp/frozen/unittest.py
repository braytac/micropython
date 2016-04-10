class TestException(Exception):
    pass

class TestCase (object):
    testCounter=0
    testOKCounter=0

    def setUp(self):
        pass
    
    def tearDown(self):
        pass

    def assertTrue(self,v,m):
        if v == False:
            raise TestException(m)

    def assertFalse(self,v,m):
        if v == True:
            raise TestException(m)

    def assertEqual(self,v1,v2,m):
        if v1 != v2:
            raise TestException(m)

    def assertNotEqual(self,v1,v2,m):
        if v1 == v2:
            raise TestException(m)

    def assertIsNone(self,v,m):
        if v != None:
            raise TestException(m)

    def assertIsNotNone(self,v,m):
        if v == None:
            raise TestException(m)

    def assertIsInstance(self,o,c,m):
        if isinstance(o,c) == False:
            raise TestException(m)

    def assertIsNotInstance(self,o,c,m):
        if isinstance(o,c) == True:
            raise TestException(m)

    @staticmethod
    def run(o):
        i=1
        o.setUp()
        while True:
            mName = "test_"+str(i)
            if hasattr(o,mName):
                m = getattr(o,mName)
                print("Testing "+mName+" ... ")
                TestCase.testCounter+=1
                try:
                    m()
                    print("OK")
                    TestCase.testOKCounter+=1
                except Exception as e:
                    print(e)
                    break
            else:
                break
            i+=1
        o.tearDown()


    @staticmethod
    def printStatistics():
        print("Tests:"+str(TestCase.testCounter)+" Errors:"+str(TestCase.testCounter-TestCase.testOKCounter))