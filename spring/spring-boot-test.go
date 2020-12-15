1. https://www.baeldung.com/spring-boot-testing

@RunWith(SpringRunner.class)
provides a bridge between Spring Boot test features and JUnit.
Whenever we are using any Spring Boot testing features in our JUnit tests, this annotation will be required.
H2 Database is required be configured, an in memory database.

@MTestConfiguration
to have an instance of the Service class created and available as a @Bean so that we can @Autowire it in our test class.
We can achieve this configuration using the @TestConfiguration annotation.
Spring Boot provides the @TestConfiguration that we can add on classes in src/test/java to indicate that they should
not be picked up by scanning,

@MockBean
It creates a Mock for a bean,
e.g.
@Before
public void setUp() {
	Employee alex = new Employee("alex");
	Mockito.when(employeeDao.findByName(alex.getName())).thenReturn(alex);
}
since the setup is done, the test case will be simpler.
@Test
public void whenValidName_thenEmployeeSHOuldBeFound() {
	String name = "alex";
	Employee found = employeeService.getEmployeeByName(name);
	assertThat(found.getName())).isEqualTo(name);
}

@WebMvcTest
use this annotation to test controller.

@SpringBootTest
integration testing with @SpringBootTest
integration test focus on integrating different layers of the application.
This annotation is useful when we need to bootstrap the entire application.
