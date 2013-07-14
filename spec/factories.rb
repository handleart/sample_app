FactoryGirl.define do
 factory :user do
 	sequence(:name) { |n| "Person #{n}"}
 	sequence(:email) { |n| "Email_#{n}@example.com"}
  	password "pa$$word123"
  	password_confirmation "pa$$word123"

  	factory :admin do
  		admin true
  	end
 end
end
