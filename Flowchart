graph TD
    A[Start Program] --> B[Display Plan Comparison & Prices]
    B --> C{Collect 10 Inputs}
    
    subgraph Inputs
    C --> C1[Listener Type]
    C --> C2[Situation]
    C --> C3[Budget]
    C --> C4[Student Eligibility]
    C --> C5[Ads Acceptance]
    C --> C6[Discovery Preference]
    C --> C7[Music Genre]
    C --> C8[Weekly Listening Hours]
    end

    C8 --> D[Score Calculation Engine]
    
    subgraph Logic
    D --> D1[3 Switch Blocks]
    D --> D2[10+ If-Else Checks]
    end

    D2 --> E{Compare Scores}
    E --> F[Highest Score = Recommendation]
    
    F --> G[Math: Calculate Cost per Hour]
    G --> H[User Feedback: Rating & Review]
    
    H --> I[Store in Vector & Save to .txt File]
    I --> J{Run Again?}
    J -- Yes --> B
    J -- No --> K[End Program]
