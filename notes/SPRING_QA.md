1. What is IoC?
    IoC stands for Inversion of Control.
    Normally, in traditional programming, your code controls the creation and wiring of objects.
    In IoC, the control is inverted: the framework (Spring) creates objects and injects dependencies.
    ✅ Key idea: “Don’t create your dependencies manually; let the container provide them.”

2. What is the Spring IoC Container?
    The IoC container is the core of the Spring Framework that:
    Creates beans (objects managed by Spring)
    Configures beans (injects dependencies)
    Manages bean lifecycle (init, post-process, destroy)
    It reads configuration from:
    XML files (older style)
    Java annotations/config classes (modern style)
    Java configuration classes with @Configuration (most common now)

 # IOC VS DI
    * IoC is the concept;
    * DI is the mechanism to achieve it.
    * IoC: Spring controls object creation and lifecycle.
    * DI (@Autowired): Spring injects dependencies into those objects.
    * Behind the scenes: AutowiredAnnotationBeanPostProcessor uses reflection to resolve and inject dependencies from the container.

# @Autowired Behind the sence
    @Autowired is a Spring annotation used to let the IoC container inject dependencies automatically.
    When Spring starts up, it scans for beans and automatically wires dependencies where @Autowired is found.

3. How it Works (Conceptually)
    You define beans (with @Component, @Service, @Repository, @Bean, etc.).
    The IoC container scans these definitions.
    It creates and wires beans automatically.
    You can retrieve beans from the container or inject them via @Autowired.

4. How are Spring Data repositories implemented by Spring at runtime?
    - Spring Data repositories are implemented at runtime by Spring using dynamic proxy classes (via JDK or CGLIB), created by the RepositoryFactoryBean mechanism.
    - A JDK proxy instance is created, which backs the repository interface, and a MethodInterceptor intercepts calls to the instance and routes as required.


5. What is SpEL and how is it used in Spring?
    - SpEL(Spring Expression Language) supports boolean and relational operators and regular expressions, and is used for querying a graph of objects at runtime.

6. The process of linking aspects with other objects to create an advised object is called
    - The process of linking aspects with other objects to create an advised object is called weaving.
    
7. How are JDK Dynamic proxies and CGLIB proxies used in Spring?
    - JDK Dynamic proxy can proxy only interface, so it is used if the target implements at least one interface. 
    A CGLIB proxy can create a proxy by subclassing and is used if the target does not implement an interface. ✅

8. In what order do the @PostConstruct annotated method, the init-method parameter method on beans and the afterPropertiesSet() method execute?
    -  @PostConstruct → 2. afterPropertiesSet() → 3. init-method ✅

9. What is the function of the @Transactional annotation at the class level?
    - It creates a proxy that implements the same interface(s) as the annotated class, allowing Spring to inject behaviors before, after, or around method calls into the object being proxied. ✅

10. What is the root interface for accessing a Spring bean container?
    - BeanFactory is the fundamental interface for accessing Spring beans.
    - ApplicationContext extends BeanFactory and adds more features like internationalization, event propagation, and resource loading.

11. Which annotation can be used within Spring Security to apply method level security?
   -  Use @Secured to restrict access to methods based on user roles in Spring Security.

12. How filters are used in Spring Web?
    - Filters are used to validate request parameters out of the byte stream request body and allow for processing of requests from the DispatcherRequestServlet.

13. What does the @SpringBootApplication annotation do?
    - The annotation is a convenience for configuring a Spring application that declares one or more @Bean methods and triggers auto-configuration.

14. How does Spring Boot handle configuration?
    - Spring Boot allows configuration through properties files, YAML files, and XML, providing flexibility in how properties are managed.

15. Which module of Spring Framework is the foundation for Spring Boot?
    - Spring Core provides the fundamental parts of the framework, such as dependency injection, which are essential for Spring Boot.

16. What is the advantage of the Spring Boot Actuator?
    - Spring Boot Actuator provides powerful features to help you monitor and manage your Spring Boot application.

17. How can you externalize configuration in a Spring Boot application?
    - Configuration can be externalized in Spring Boot using environment variables, allowing different settings for different environments.

18. What role does Spring Boot DevTools play?
    - Spring Boot DevTools provides features like automatic restart and live reload to enhance developer productivity.

19. What is the purpose of the @ConfigurationProperties annotation in a Spring Boot application?
    - The @ConfigurationProperties annotation is used to map properties from external sources, such as application.properties files or environment variables, to JavaBean properties in a Spring Boot application.

20. How can you specify a custom location for the application.properties file in a Spring Boot application?
    - The spring.config.location property can be used to specify one or more locations for the application.properties file, allowing customization of the configuration file's location.

21. What is the purpose of the @ConditionalOnProperty annotation in Spring Boot?
    - The @ConditionalOnProperty annotation is used to conditionally enable or disable beans based on the presence or value of a property in a Spring Boot application.

22. How can you access a property from the application.properties file in a Spring Boot application?
    - The @Value annotation can be used to inject a property from the application.properties file into a Spring Bean in a Spring Boot application.

23. How can you define a custom configuration property class in Spring Boot?
    - A custom configuration property class in Spring Boot can be defined by creating a Java class and annotating it with @ConfigurationProperties, allowing mapping of properties from external sources.

24. How can you load additional application properties from an external YAML file in a Spring Boot application?
    - The @PropertySource annotation can be used to load additional application properties from an external YAML file in a Spring Boot application, specifying the file path in the value attribute.

25. If a Spring Boot application fails to start due to a missing property in the application.properties file, what is the solution?
    - If a required property is missing in the application.properties file, adding the missing property to the file should resolve the issue and allow the application to start successfully.

26. What should you check first if changes to application.properties are not reflecting in your Spring Boot application?
    - Ensuring that the application.properties file is in the correct directory such as src/main/resources is crucial for Spring Boot to load the configuration properly.

27. What is a common cause of a Spring Boot configuration issue where a specific bean is not being injected as expected?
    - Conditional annotations like @ConditionalOnProperty or @ConditionalOnClass can prevent a bean from being created if certain conditions are not met. It's important to verify these conditions.

28. What is the purpose of the @PathVariable annotation in Spring Boot?
    - The @PathVariable annotation is used to extract values from the URI within a controller method, typically in RESTful web services to access a specific resource.

29. How can you handle exceptions in a Spring Boot REST API to return a custom JSON error response?
    - @ControllerAdvice allows global error handling across all controllers, and @ExceptionHandler can be used within it to handle specific exceptions and customize error responses.

30. If a REST API method in Spring Boot is unexpectedly returning 200 OK with an empty body,
    - If a REST method returns 200 OK with an empty body, it might be because the data source or business logic is returning null or no data is available to return.

31. How can you trace a request through a Spring Boot application to debug issues with REST API calls?
    - Using Spring Boot Actuator and application logs together helps trace requests through the application, providing insights into where issues may be occurring with REST API calls.

32. What does the @Transactional annotation do in a Spring Boot application?
    - The @Transactional annotation in Spring Boot manages the scope of a single database transaction, ensuring operations within the scope are part of the same transaction context.

33. How can you enable lazy loading of associations in Spring Data JPA?
    - Lazy loading in Spring Data JPA can be enabled by setting the fetch type of associations to FetchType.LAZY, which loads the associations on demand rather than immediately.

34. In Spring Data, how can you dynamically construct queries using method names in your repository interface?
    - In Spring Data, you can dynamically construct queries by naming repository interface methods according to a specific naming convention that reflects entity properties.

35. What common issue might cause a DataIntegrityViolationException in a Spring Boot application using JPA?
    - DataIntegrityViolationException typically occurs due to constraint violations in the database, such as unique constraints, foreign keys, or not null constraints being violated.

36. If a Spring Boot application fails to connect to the database, what could be potential issues to check?
    - Common issues that could prevent a Spring Boot application from connecting to a database include incorrect database URL or credentials, network issues, or driver misconfiguration.

37. How can you resolve a LazyInitializationException in a Spring Boot application using Hibernate?
    - LazyInitializationException typically occurs when lazily loaded data is accessed after the Hibernate session is closed. Keeping the session open or accessing data within a transaction can resolve this.

38. Which module in Spring Boot provides support for securing web applications?
    - Spring Security provides comprehensive security services for Java applications, including authentication, authorization, and protection against common exploits.

39. What is the primary use of the @PreAuthorize annotation in Spring Security?
    - The @PreAuthorize annotation allows method-level security, enabling the specification of access-control expressions that are evaluated before executing a method.

40. How does Spring Boot automatically secure web applications?
    - Spring Boot can automatically secure web applications by configuring basic authentication, requiring users to authenticate before accessing any web application resources.

41. In Spring Security, what is the function of the WebSecurityConfigurerAdapter?
    - The WebSecurityConfigurerAdapter is a convenience class that allows customization of both web security and HTTP security, enabling detailed control over security settings.

42. How can you configure a custom login page in Spring Boot using Spring Security?
    - To configure a custom login page in Spring Security, you can override the default security configuration using the WebSecurityConfigurerAdapter.

45. What is the role of the UserDetailsService interface in Spring Security?
    - The UserDetailsService interface is central in Spring Security for loading user-specific data. It is often used to customize authentication by providing a custom implementation.

46. If Spring Security is blocking access to a resource that should be public, what is a common solution?
    - Often, adjusting the order in which security rules are evaluated in the configuration can resolve issues where resources are incorrectly blocked by Spring Security.

47. How does Spring Boot simplify integration testing with databases?
    - Spring Boot can auto-configure embedded databases like H2, making them available during integration testing, which simplifies the database environment setup.

48. What is the purpose of the @WebMvcTest annotation in Spring Boot testing?
    - @WebMvcTest is used for testing the web layer only and does not load the full application context, focusing instead on controllers and related web components.

49. What should you check if a user's authentication is failing in a Spring Boot application secured with Spring Security?
    - Authentication failures often stem from issues in the security configuration, such as incorrect setup in WebSecurityConfigurerAdapter or problems with user credentials.

50. How can you debug issues with role-based access controls not working as expected in Spring Boot?
    - To debug issues with role-based access controls, reviewing and possibly adjusting the security configuration and role assignments within WebSecurityConfigurerAdapter is essential.

51. Which Spring Boot test annotation is typically used to configure JSON assertions in a test method?
    - @JsonTest is used for testing JSON serialization and deserialization in Spring Boot applications, focusing on the JSON aspects of Spring application data.

52. How do you use the @DataJpaTest annotation in Spring Boot?
    - @DataJpaTest is used specifically for testing JPA repositories. It configures an in-memory database, scans for @Entity classes, and configures Spring Data JPA repositories.

53. What functionality does the @RestClientTest annotation provide in Spring Boot testing?
    - @RestClientTest is used for testing REST clients. It auto-configures JSON mappers and can focus on parts of Spring that deal with outbound web requests.

54. What is a common strategy to resolve issues when a test fails to load the Spring context?
    - Checking for configuration errors, such as incorrect application properties or misconfigured beans, is a common strategy when a test fails due to Spring context issues.

55. If a Spring Boot test intermittently fails, what might be the probable cause? 
    - Intermittent test failures in Spring Boot often point to issues like race conditions in asynchronous operations, where tests do not consistently account for timing issues.

56. How can you diagnose problems with Spring Boot auto-configuration in tests?
    - You can diagnose problems with Spring Boot auto-configuration in tests by enabling debug output or using the ApplicationContextRunner and auto-configuration reports to inspect which configurations are applied or excluded.
    - Enabling detailed logging for Spring Boot's auto-configuration during testing can help identify misconfigurations or conflicts that cause test failures.

57. What role does Spring Cloud play in the Spring Boot microservices architecture?
    - Spring Cloud provides a set of tools and frameworks that help developers implement common patterns in distributed systems (microservices), such as configuration management, service discovery, circuit breakers, etc.

58. How does the Config Server in Spring Cloud benefit microservices?
    * Answer: It provides centralized configuration management.
    - The Config Server in Spring Cloud provides a central place for managing external properties for applications across all environments, making configuration changes easier without redeploying.

59. How does Spring Boot handle versioning in a microservices architecture?
    Answer: By using URI versioning.
    Explanation : URI versioning involves using different URLs for different versions of the same service, allowing multiple versions to operate simultaneously and clients to specify the version they wish to use.

60. What is a Circuit Breaker in microservices, and how is it implemented in Spring Boot?
    - Answer: It prevents the application from making unnecessary calls to a service that is likely down.
    - Explanation: The Circuit Breaker pattern, implemented in Spring Boot using libraries like Resilience4j, prevents an application from performing operations that are likely to fail, thus maintaining stability and performance.

61. Which annotation is used to create a REST client in Spring Boot microservices?
    - Answer: @FeignClient
    - Explanation @FeignClient is used in Spring Boot to declare and implement REST clients easily. It abstracts the details of REST interactions and integrates with service discovery mechanisms like Eureka.

62. How do you enable a service to register with Eureka server in a Spring Boot application?
    - Answer: By annotating the main application class with @EnableEurekaClient.
    - Explanation @EnableEurekaClient or @EnableDiscoveryClient can be used to allow a Spring Boot application to register as a service with a Eureka Discovery Server, enabling service discovery.

63. What is the best practice for integrating a microservices architecture with a messaging system like Kafka in Spring Boot?
    - Answer: Using Spring Cloud Stream.
    - Explanation: Spring Cloud Stream is a framework for building highly scalable event-driven microservices connected with shared messaging systems, and it provides a robust abstraction for interacting with messaging systems like Kafka.

64. How can you identify performance bottlenecks in a microservice architecture using Spring Boot?
    - Answer: By using application performance monitoring tools.
    - Explanation Application performance monitoring (APM) tools are essential for identifying and diagnosing performance issues in microservices, allowing developers to monitor and trace transactions across services.

65. What steps should you take if a particular service in a microservices architecture fails to start?
    - Answer: Check the service’s logs for errors.
    - Explanation When a microservice fails to start, checking the service's logs is the first step to identify any errors or exceptions that might be causing the failure.

66. How do you handle a scenario where a microservice intermittently fails to communicate with other services?
    Answer: Implementing retry mechanisms and fallbacks.
    Explanation: Implementing retry mechanisms and fallbacks, such as through a Circuit Breaker, helps manage temporary failures in microservice communication by retrying operations or providing fallback solutions.

67. Which endpoint in Spring Boot Actuator provides details about the health of the application?
    Answer: /health
    Explanation: The /health endpoint provides basic information about the health of the application, showing status information about various components like database, disk space, etc.

68. What information can be accessed through the /metrics endpoint of Spring Boot Actuator?
    Answer: Application performance metrics.
    Explanation: The /metrics endpoint exposes various metrics information, such as memory usage, HTTP request metrics, and system health, which are crucial for monitoring the application.

69. How can you customize which endpoints are exposed by Spring Boot Actuator?
    Answer: By modifying the application.properties file.
    Explanation: Endpoints exposed by Spring Boot Actuator can be customized through properties defined in application.properties or application.yml, controlling their exposure and security.

70. How does the /audit endpoint of Spring Boot Actuator help in application management?
    Answer: It provides a log of security access events.
    Explanation: The /audit endpoint is useful for tracking access and changes to the application, especially in a production environment, providing an audit trail of security-related events.

71. What is required to create a custom Actuator endpoint in Spring Boot?
    Answer: Annotating a class with @Endpoint and defining read or write operations.
    Explanation: Creating a custom Actuator endpoint involves annotating a class with @Endpoint and defining necessary operations, which allows for extending the monitoring capabilities with specific functionalities.

72. What common issue might cause the Actuator /health endpoint to show a status of "DOWN"?
    Answer: Database connectivity issues.
    Explanation: If the /health endpoint shows a status of "DOWN", it often indicates issues with essential components such as database connections, which are crucial for the application's operations.

73. How can you diagnose issues with slow response times reported by the Actuator /metrics endpoint?
    Answer: By reviewing the detailed metrics logs.
    Explanation: When the /metrics endpoint indicates slow response times, reviewing the detailed logs can help identify bottlenecks in the application, such as inefficient code or resource limitations.

74. What is the primary benefit of containerizing a Spring Boot application?
    Answer: Scalability and easy deployment
    Explanation: Containerizing a Spring Boot application provides scalability and facilitates easy deployment across different environments, making it easier to manage and scale applications regardless of the underlying infrastructure.

75. Which file is crucial for defining a container's configuration for a Spring Boot application?
    Answer: Dockerfile
    Explanation: The Dockerfile defines the container configuration, specifying how the Spring Boot application is built, what base image to use, and any dependencies or commands required for running the application.

76. How does Docker Compose benefit Spring Boot application development?
    Answer: By enabling the integration of multiple containers
    Explanation: Docker Compose allows developers to define and run multi-container Docker applications, where each service can be containerized, facilitating complex applications that consist of multiple services.

77. What is a best practice for managing application configurations in a containerized Spring Boot environment?
    Answer: Using external configuration files
    Explanation: Using external configuration files or environment variables is a best practice for managing configurations in a containerized environment, allowing for more flexibility and easier configuration management across deployments.

78. How do you specify a base image in a Dockerfile for a Spring Boot application?
    Answer: Using the FROM directive
    Explanation: The FROM directive in a Dockerfile is used to specify the base image from which the container is built, setting up the operating system and any base layers needed for the application.

79. What is a common issue when a Spring Boot application in a Docker container fails to connect to external services?
    Answer: Incorrect network settings
    Explanation: Incorrect network configuration is a common issue when Dockerized Spring Boot applications fail to connect to external services, often due to misconfigured Docker networking options or errors in specifying external endpoints.

80. How can you troubleshoot a Spring Boot application that starts in a Docker container but is not accessible externally?
    Explanation: When a Spring Boot application is not accessible externally, troubleshooting steps include checking Docker container logs for errors, verifying network settings and exposed ports to ensure the application is reachable from outside the container.

81. In reactive programming with Spring Boot, what role does the Project Reactor play?
    Answer: It provides a reactive library for implementing reactive APIs
    Explanation: Project Reactor is a foundational library for reactive programming in the Spring ecosystem, offering APIs for reactive streams, which are essential for building non-blocking and asynchronous applications.

82. How does backpressure control the flow of data in reactive programming?
    Answer: By limiting data flow based on consumer capacity
    Explanation: Backpressure is a mechanism in reactive programming that allows consumers to control the rate at which producers emit data, ensuring that the consumer can handle the incoming data without being overwhelmed.

83. What is the main advantage of using reactive programming for data streams in Spring Boot?
    Answer: Ability to handle large numbers of concurrent data streams efficiently
    Explanation: Reactive programming allows efficient handling of large numbers of concurrent data streams, making it suitable for applications with high throughput and dynamic data flows, such as real-time data processing.

84. How do you define a Mono object that returns a single value asynchronously in Spring Boot's WebFlux?
    Answer: Using Mono.create()
    Explanation: Mono.create() is used in WebFlux to programmatically create a Mono which emits a single asynchronous value, providing a way to integrate callbacks and other asynchronous processes into the reactive data pipeline.

85. What method can be used to combine multiple reactive streams in Spring Boot?
    Answer: Flux.merge()
    Explanation: Flux.merge() is used to merge multiple reactive streams into one, allowing different streams to be processed together, which can be useful in scenarios where streams from various sources need to be handled in a unified manner.

86. Which operator in Project Reactor is used to handle errors in a reactive stream?
    Answer: onErrorReturn()
    Explanation: The onErrorReturn() operator in Project Reactor is used to provide a fallback value when an error occurs in a reactive stream, enabling the stream to continue functioning with a default value instead of terminating.

87. When debugging a non-responsive reactive API in Spring Boot, what is an initial step to identify the issue?
    Answer: Verifying the reactive chain for blocking calls
    Explanation: When a reactive API is non-responsive, an important step in debugging is to verify the reactive chain to ensure there are no blocking calls that might stall the reactive flow, as this goes against the reactive paradigm.

88. How can you trace and diagnose issues in a Spring Boot application using reactive programming?
    Answer: Incorporating logging and tracing frameworks like Sleuth
    Explanation: Using logging and tracing frameworks such as Spring Cloud Sleuth can help trace and diagnose issues in reactive applications by providing detailed logs and tracing information across asynchronous boundaries.

89. How does the @Conditional annotation enhance Spring Boot's configuration capabilities?
    Answer: By allowing beans to be loaded based on specific conditions
    Explanation: @Conditional provides advanced configuration options by allowing beans to be created only when specific conditions are met, thus customizing the application setup based on the runtime environment or custom logic.

90. In what way does externalized configuration benefit a Spring Boot application?
    Answer: It allows configurations to be changed at runtime without redeployment
    Explanation: Externalizing configuration out of the application itself and into external sources enables changes to configuration without the need to rebuild or redeploy the application, enhancing flexibility and maintainability.

91. What role does Spring Cloud Config play in managing Spring Boot application configurations?
    Answer: It serves as a central server for managing external properties across all environments
    Explanation: Spring Cloud Config provides a server and repository system for externalizing configuration properties, especially useful in microservices architecture to ensure consistency across services.

92. How do you specify a property source in a Spring Boot application if the properties file is not named application.properties?
    Answer: By using the @PropertySource annotation
    Explanation: The @PropertySource annotation is used to declare a path to a properties file that Spring Boot should load in addition to the default ones, offering flexibility in configuration management.

93. How can you dynamically switch between different data sources in a Spring Boot application based on a specific condition?
    Answer: By using @Conditional on data source configurations
    Explanation: The @Conditional annotation can be used on data source configuration methods to create and expose different data sources based on certain conditions, allowing dynamic switching at runtime.

94. What is a method for applying fine-grained traffic routing rules in a Spring Boot application when using microservices?
    Answer: Using Netflix Zuul as an API gateway
    Explanation: Netflix Zuul can be integrated into Spring Boot applications to act as an API gateway, where it can handle routing, filtering, and providing security measures at the edge of the system.

95. What should you check first if your @Conditional bean does not load in a Spring Boot application?
    Answer: The condition's logic
    Explanation: If a @Conditional bean is not loading, the first step should be to verify the logic of the condition attached to the bean to ensure that it matches the current application environment or context.

96. How can you resolve issues related to external configuration properties not being recognized by a Spring Boot application?
    Answer: Check the property file's location and format
    Explanation: Common issues with external configuration properties often involve incorrect file location or format errors. Ensuring that the properties files are correctly located and formatted can resolve these issues.

97. Which deployment option is natively supported by Spring Boot for web applications?
    Answer: Deploying as a standalone JAR
    Explanation: Spring Boot natively supports building standalone applications as JARs, which can be run using java -jar, simplifying the deployment process without needing an external server.

98. What is a benefit of using containerization with Docker for deploying Spring Boot applications?
    Answer: Scalability and easy version control
    Explanation: Containerization, such as using Docker, provides scalability by allowing multiple containers to be deployed easily and version control through image management.

99. What does the Spring Boot Maven plugin provide for application deployment?
    Answer: It automates the application deployment process.
    Explanation: The Spring Boot Maven plugin simplifies the deployment process by packaging applications and their dependencies into a single executable JAR or WAR, including support for embedded servers.

100. What command is used to build a Spring Boot application using Maven for deployment?
    Answer: mvn package
    Explanation: The mvn package command compiles the application and packages it into a JAR or WAR file, ready for deployment, making it the appropriate choice for building Spring Boot applications.

101. How can you address a failure in a Spring Boot application when it starts but is inaccessible externally?
    Answer: Check firewall settings and network configuration
    Explanation: Checking firewall settings and network configuration is crucial when the application starts but is not accessible externally, as these settings can block incoming traffic to the application.

102. How does Kafka's partitioning feature enhance message processing in Spring Boot applications?
    Answer: By allowing concurrent processing of messages
    Explanation: Kafka's partitioning allows messages to be processed concurrently across multiple consumer instances, enhancing throughput and efficiency in processing large volumes of data.

101. What is the purpose of a Kafka Consumer Group in the context of Spring Boot integration?
    Answer: To provide fault tolerance
    Explanation: In Kafka, a consumer group consists of multiple consumers who work together to process data. This grouping provides fault tolerance by ensuring messages are processed even if a consumer fails.

102. How does Kafka ensure data durability and high availability in Spring Boot applications?
    Answer: By replicating data across multiple nodes
    Explanation: Kafka ensures durability and high availability by replicating data across multiple nodes within the cluster. This replication allows the system to recover from node failures without data loss.

103. How can you configure a Kafka Producer in a Spring Boot application to send messages asynchronously?
    Answer: By calling the send() method with a callback
    Explanation: Asynchronous message sending in Kafka can be achieved by calling the send() method with a callback. This allows the producer to continue processing while the broker handles message delivery.

104. What is the advantage of enabling idempotence in a Kafka Producer configuration within a Spring Boot application?
    Answer: To ensure messages are only processed once, even if sent multiple times
    Explanation: Idempotence in Kafka producers ensures that messages are delivered exactly once, preventing duplicate processing of messages even in the event of retries, which is crucial for maintaining data consistency.

105. What should you check if messages are not being received by a Kafka Consumer in a Spring Boot application?
    Answer: The topic subscription details
    Explanation: When a Kafka Consumer isn't receiving messages, it's essential to verify that the consumer is subscribed to the correct topics, as this is a common configuration issue.

106. How can you troubleshoot issues related to message order in a Kafka stream consumed by a Spring Boot application?
    Answer: By ensuring all messages are sent to the same partition
    Explanation: To maintain the order of messages in Kafka, ensuring that messages that need to be consumed in order are sent to the same partition is crucial, as messages within a partition are guaranteed to be in the order they were sent.

107. What is the significance of Micrometer in the context of Spring Boot applications?
    Answer: It is a metrics integration tool.
    Explanation: Micrometer functions as a metrics facade for integrating with various monitoring systems, allowing Spring Boot applications to collect a broad range of operational metrics seamlessly.

108. What is the purpose of using the @Timed annotation in Spring Boot applications?
    Answer: To measure the response time of methods
    Explanation: The @Timed annotation is used to measure how long a method or some code takes to execute, which helps in identifying performance bottlenecks by tracking response times.

109. How can you implement custom metrics in a Spring Boot application using Micrometer?
    Answer: By using the Counter and Gauge classes from Micrometer
    Explanation: Micrometer's Counter and Gauge are among the several types of measurements it supports for tracking application metrics, which can be used to implement custom metrics that track specific behaviors or operations.

110. What approach should be taken to optimize the performance of a Spring Boot application experiencing slow load times?
    Answer: Profiling and identifying bottlenecks
    Explanation: Profiling an application and identifying bottlenecks are critical steps in optimizing performance, as this allows developers to pinpoint specific areas that need improvement.

111. How can you effectively manage exceptions in a Spring Boot application?
    Answer: By using a global exception handler
    Explanation: Implementing a global exception handler using @ControllerAdvice allows for centralized exception management, providing a consistent strategy for handling exceptions across the application.

112. What is a best practice when creating RESTful APIs in Spring Boot?
    Answer: Using meaningful HTTP verbs and URIs Explanation
    Best practices for RESTful API design include using meaningful HTTP verbs (GET, POST, DELETE, PUT) and URIs that clearly represent the underlying operations and resources.

113. How can Spring Boot help in improving the security of an application?
    Answer: By providing ready-to-use security configurations
    Explanation: Spring Boot offers security configurations that can be easily integrated into applications, providing robust security measures like CSRF protection and default security headers.

114. What is a recommended practice for managing application configurations in Spring Boot?
    Answer: Using external configuration files
    Explanation: Using external configuration files allows for flexibility and easier management of different environments without needing to rebuild or recompile the code.

# Authentication → “Who are you?”
    * Authentication is the process of verifying a user’s identity — checking who is trying to access the system.
    * Authentication → showing your ID card at the door (proving you work there).

# Authorization → “What can you do?”
    * Authorization happens after authentication — it determines what actions or resources the authenticated user is allowed to access.
    * Authorization → which floors or rooms your ID gives you access to (your permissions).


# Common Lombok Annotations
* Project Lombok is a Java library that automatically generates common boilerplate code (like getters, setters, constructors, toString(), etc.) at compile time, using annotations.
---------------------------------------------------------------------------- ---------------------------------------------------------------------------------------------------
| Annotation                                                                | Purpose                                                                                          |
| ------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| `@Getter` / `@Setter`                                                     | Auto-generates getters and setters                                                               |
| `@ToString`                                                               | Creates `toString()` method                                                                      |
| `@EqualsAndHashCode`                                                      | Generates `equals()` and `hashCode()`                                                            |
| `@NoArgsConstructor` / `@AllArgsConstructor` / `@RequiredArgsConstructor` | Generates constructors                                                                           |
| `@Data`                                                                   | Combines `@Getter`, `@Setter`, `@ToString`, `@EqualsAndHashCode`, and `@RequiredArgsConstructor` |
| `@Builder`                                                                | Enables the **Builder pattern** for creating objects                                             |
| `@Value`                                                                  | Makes an immutable class (all fields `private` and `final`)                                      |
---------------------------------------------------------------------------- --------------------------------------------------------------------------------------------------


🌐 What is Spring WebFlux?
Spring WebFlux is a reactive, non-blocking web framework introduced in Spring 5.
It is designed for asynchronous, event-driven applications that need to handle massive concurrency with fewer resources.
It uses the Reactive Streams API, based on Project Reactor (Mono and Flux types).

------------------------- ---------------------------------------------------------------------------------
| **Aspect**             | **Description**                                                                |
| ---------------------- | ------------------------------------------------------------------------------ |
| **Framework Type**     | Reactive and non-blocking web framework                                        |
| **Introduced In**      | Spring Framework 5                                                             |
| **Programming Model**  | Reactive Streams (using `Mono` and `Flux`)                                     |
| **Core Library**       | Project Reactor                                                                |
| **Server Support**     | Netty, Undertow, Jetty, Tomcat (as reactive runtimes)                          |
| **Entry Point**        | `@Controller`, `@RestController`, or **functional routing** (`RouterFunction`) |
| **Return Types**       | `Mono<T>` (0–1 item) and `Flux<T>` (0–N items)                                 |
| **Performance Goal**   | High concurrency with low resource usage                                       |
| **Annotation Support** | Same as Spring MVC (`@RequestMapping`, `@GetMapping`, etc.)                    |
| **Compatibility**      | Works with reactive data stores (MongoDB, Cassandra, R2DBC, etc.)              |
| **Not Suitable For**   | Traditional blocking I/O like JDBC or file I/O                                 |
------------------------- ---------------------------------------------------------------------------------

# ⚙️ When to Use Spring WebFlux
----------------------------- -------------------------------------------------------------------
| **Use Case**               | **Why Use WebFlux**                                              |
| -------------------------- | ---------------------------------------------------------------- |
| **High concurrency APIs**  | Handles thousands of requests with fewer threads                 |
| **Streaming data**         | Ideal for real-time data streams (e.g., stock prices, chat apps) |
| **Microservices**          | Works well with reactive message brokers like Kafka/RabbitMQ     |
| **Reactive databases**     | Perfect for non-blocking DBs (MongoDB Reactive, R2DBC)           |
| **Server-to-server calls** | When services call other services asynchronously                 |
| **Event-driven systems**   | Naturally fits systems using reactive event flows                |
----------------------------- -------------------------------------------------------------------

# 🔄 Spring MVC vs Spring WebFlux Comparison
------------------------------ ---------------------------------- ----------------------------------------------
| **Feature**                | **Spring MVC (Blocking)**         | **Spring WebFlux (Non-Blocking)**           |
| -------------------------- | --------------------------------- | ------------------------------------------- |
| **I/O Model**              | Synchronous (blocking)            | Asynchronous (non-blocking)                 |
| **Concurrency Model**      | One thread per request            | Event-loop, few threads for many requests   |
| **Performance**            | Good for small/medium load        | Excellent for high concurrency              |
| **Server Type**            | Servlet container (Tomcat, Jetty) | Reactive runtime (Netty, Undertow, etc.)    |
| **Return Type**            | Plain objects / `ResponseEntity`  | `Mono<T>` / `Flux<T>`                       |
| **Backpressure Support**   | ❌ No                              | ✅ Yes                                       |
| **Programming Model**      | Imperative                        | Reactive / Functional                       |
| **Use Case**               | CRUD, blocking DB operations      | Streaming, reactive APIs                    |
| **Database Compatibility** | JDBC, JPA                         | Reactive DBs (R2DBC, Reactive Mongo)        |
| **Learning Curve**         | Easier                            | Steeper (requires understanding of Reactor) |
----------------------------- ------------------------------------ --------------------------------------------

# 💡 Key Components
-------------------------------------------- ----------------------------------------------------
| **Component**                            | **Purpose**                                        |
| ---------------------------------------- | -------------------------------------------------- |
| **`Mono<T>`**                            | Emits 0 or 1 element (like `Optional` or `Future`) |
| **`Flux<T>`**                            | Emits 0 to many elements (like a stream)           |
| **`WebClient`**                          | Reactive alternative to `RestTemplate`             |
| **`RouterFunction` / `HandlerFunction`** | Functional programming style routing               |
| **`@Controller` / `@RestController`**    | Annotation-based reactive controllers              |
| **`ServerResponse` / `ServerRequest`**   | Used in functional endpoints                       |
| **`Reactor`**                            | Core reactive engine used by WebFlux               |
------------------------------------------- -----------------------------------------------------

# Bean Scope

Lifecycle can vary based on bean scope:

-------------- ----------------------------------------------------------------------------------
| Scope       | Lifecycle Notes                                                                 |
| ----------- | ------------------------------------------------------------------------------- |
| Singleton   | One instance per container → full lifecycle applies                             |
| Prototype   | New instance every time → init called, but container doesn’t manage destruction |
| Request     | One per HTTP request                                                            |
| Session     | One per HTTP session                                                            |
| Application | One per ServletContext                                                          |
-------------- ----------------------------------------------------------------------------------


# Lifecycle Summary Diagram (Textual)
Bean Instantiation
       ↓
Dependency Injection (Populate Properties)
       ↓
BeanNameAware / BeanFactoryAware (optional)
       ↓
postProcessBeforeInitialization
       ↓
Custom Init (@PostConstruct / afterPropertiesSet)
       ↓
postProcessAfterInitialization
       ↓
Bean Ready to Use
       ↓
Container Shutdown → @PreDestroy / destroy()



# Types of IoC Containers in Spring
----------------------------- ---------------------------------------------------------------------------------------------------------------------------------------------------------
| Container                 | Description                                                                                                                                             |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **BeanFactory**           | The simplest container. Lazily instantiates beans. Basic DI support.                                                                                    |
| **ApplicationContext**    | Most commonly used. Extends BeanFactory. Eagerly instantiates singleton beans. Adds features like internationalization, event propagation, AOP support. |
| **WebApplicationContext** | Specialized for web apps. Supports servlet context, scopes like `request` and `session`.                                                                |
---------------------------- ----------------------------------------------------------------------------------------------------------------------------------------------------------


# Spring AOP
-------------------- --------------------------------------------------------------------------------
| Annotation        | Description                                                                    |
| ----------------- | ------------------------------------------------------------------------------ |
| `@Before`         | Runs **before** a matched method executes.                                     |
| `@After`          | Runs **after** a matched method executes (regardless of outcome).              |
| `@AfterReturning` | Runs **after** a method executes **successfully** (no exception).              |
| `@AfterThrowing`  | Runs **if a method throws an exception**.                                      |
| `@Around`         | Runs **before and after** a method — gives full control over method execution. |
-------------------- --------------------------------------------------------------------------------

# AOP JOIN POINT
-------------------- -----------------------------------------------------------
| Method            | Description                                              |
| ----------------- | -------------------------------------------------------- |
| `getArgs()`       | Returns an array of the arguments passed to the method.  |
| `getTarget()`     | Returns the target object being advised.                 |
| `getSignature()`  | Returns the method signature being advised.              |
| `getThis()`       | Returns the proxy object.                                |
| `toShortString()` | Returns a concise description of the join point.         |
| `toLongString()`  | Returns a detailed description of the join point.        |
| `getKind()`       | Returns the kind of join point (e.g., method execution). |
-------------------- ----------------------------------------------------------

# View Resolver
------------------------------------- ------------------------------------------------------------
| ViewResolver                       | Description                                               |
| ---------------------------------- | --------------------------------------------------------- |
| **`InternalResourceViewResolver`** | Maps view names to JSP files (common in traditional MVC). |
| **`ThymeleafViewResolver`**        | Used when using Thymeleaf templates.                      |
| **`FreeMarkerViewResolver`**       | Used for FreeMarker templates.                            |
| **`BeanNameViewResolver`**         | Resolves view names to beans defined in the context.      |
------------------------------------- ------------------------------------------------------------


# Spring Boot Actuator Summary Table
-------------------------------------- ------------------------------------------------------------------ ------------------------------ -------------------------------------------
| **Feature / Endpoint**              | **Purpose**                                                      | **Default Path**             | **Requires Authentication (by default)** |
| ----------------------------------- | ---------------------------------------------------------------- | ---------------------------- | ---------------------------------------- |
| **/actuator**                       | Shows available actuator endpoints                               | `/actuator`                  | No                                       |
| **/actuator/health**                | Shows application health status (e.g., UP, DOWN)                 | `/actuator/health`           | No (basic info)                          |
| **/actuator/info**                  | Displays arbitrary application info (e.g., version, description) | `/actuator/info`             | No                                       |
| **/actuator/metrics**               | Shows application metrics (CPU, memory, requests, etc.)          | `/actuator/metrics`          | Yes                                      |
| **/actuator/metrics/{metric-name}** | Detailed metric info (e.g., `/actuator/metrics/jvm.memory.used`) | `/actuator/metrics/{metric}` | Yes                                      |
| **/actuator/env**                   | Displays environment properties (system, config, etc.)           | `/actuator/env`              | Yes                                      |
| **/actuator/beans**                 | Shows all Spring beans and their dependencies                    | `/actuator/beans`            | Yes                                      |
| **/actuator/mappings**              | Shows all request mappings in the application                    | `/actuator/mappings`         | Yes                                      |
| **/actuator/loggers**               | View and configure log levels at runtime                         | `/actuator/loggers`          | Yes                                      |
| **/actuator/threaddump**            | Displays thread dump of running threads                          | `/actuator/threaddump`       | Yes                                      |
| **/actuator/heapdump**              | Generates a JVM heap dump file                                   | `/actuator/heapdump`         | Yes                                      |
| **/actuator/shutdown**              | Gracefully shuts down the application                            | `/actuator/shutdown`         | Yes (and must be explicitly enabled)     |
| **/actuator/httptrace**             | Shows recent HTTP request traces (requires HTTP tracing enabled) | `/actuator/httptrace`        | Yes                                      |
| **/actuator/auditevents**           | Shows security-related audit events                              | `/actuator/auditevents`      | Yes                                      |
| **/actuator/scheduledtasks**        | Displays all scheduled tasks                                     | `/actuator/scheduledtasks`   | Yes                                      |
-------------------------------------- ------------------------------------------------------------------ ------------------------------ -------------------------------------------