FROM maven:3.9.6-eclipse-temurin-21-alpine AS builder
WORKDIR /app
COPY pom.xml /app/
COPY src /app/src/
RUN mvn dependency:resolve
RUN mvn package
FROM eclipse-temurin:21-jre-alpine
WORKDIR /app
COPY --from=builder /app/target/worker-jar-with-dependencies.jar /app/
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]